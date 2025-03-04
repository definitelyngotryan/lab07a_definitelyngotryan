// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	/*
	for (size_t j = 0; j < table[i].size(); ++j) {
        total += table[i][j].second;  // we could do it like this like back in java
    }*/

	int total= 0;
	for(size_t i = 0; i < CAPACITY; ++i){
		for(const auto& pair : table[i]){
			total+= pair.second;
		}
	}
	return total;
	//double for loop allows us to access into the array of vectors-- which is kind of like a 2d array from Java?
}

int WordCount::getNumUniqueWords() const {
	//each pair is unique because that's how we're storing thedata into the hashtable-- to my understanding.

	int uniqueCount = 0;
	for(size_t i = 0; i < CAPACITY; ++i){
		uniqueCount += table[i].size();
	}
    return uniqueCount;
	// Return total number of unique words that exist in the hash table.
  // Note that multiple occurrences of a word is considered one unique
  // word.
}

int WordCount::getWordCount(std::string word) const {
	word = makeValidWord(word);
    if (word.empty()) return 0;

    size_t index = hash(word);
    for (const auto& pair : table[index]) {
        if (pair.first == word) {
            return pair.second;
        }
    }
    return 0;
	// Return the number of occurences for a specific word.
  // You may not assume the parameter is a valid word and must
  // strip / convert to lower case before looking in the hash table.
  // If the word does not exist in the table, return 0

}
	
int WordCount::incrWordCount(std::string word) {
	word = makeValidWord(word);
    if (word.empty()){
		return 0;

	} 
    size_t index = hash(word);
    for (auto& pair : table[index]) {
        if (pair.first == word) {
            pair.second++;  
            return pair.second;
        }
    }
    table[index].push_back({word, 1});  
    return 1;
	
}

int WordCount::decrWordCount(std::string word) {
	word = makeValidWord(word);
    if (word.empty()) return -1;

    size_t index = hash(word);
    for (size_t i = 0; i < table[index].size(); ++i) {
        if (table[index][i].first == word) {
            if (table[index][i].second > 1) {
                table[index][i].second--;
                return table[index][i].second;
            } else {
                table[index].erase(table[index].begin() + i);
                return 0;
            }
        }
    }
    return -1;

}

bool WordCount::isWordChar(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');

	
}

std::string WordCount::makeValidWord(std::string word) {

	
	std::string valid = "";
    for (size_t i = 0; i < word.length(); i++) {
        if (isWordChar(word[i])) {
            valid += tolower(word[i]);
        } else if ((word[i] == '\'' || word[i] == '-') &&
                   i > 0 && i < word.length() - 1 &&
                   isWordChar(word[i - 1]) && isWordChar(word[i + 1])) {
            valid += word[i];  // Keep apostrophe or hyphen if inside the word
        }
    }
    return valid;


	
}


void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
    std::vector<std::pair<std::string, int>> wordList;

    for (size_t i = 0; i < CAPACITY; ++i) {
        for (const auto& pair : table[i]) {
            wordList.push_back(pair);
        }
    }

    for (size_t i = 0; i < wordList.size(); ++i) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < wordList.size(); ++j) {
            if (wordList[j].first > wordList[maxIndex].first) {
                maxIndex = j; 
            }
        }
        std::swap(wordList[i], wordList[maxIndex]); 
    }

    for (const auto& pair : wordList) {
        out << pair.first << "," << pair.second << "\n";
    }
}


void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
    std::vector<std::pair<std::string, int>> wordList;

    for (size_t i = 0; i < CAPACITY; ++i) {
        for (const auto& pair : table[i]) {
            wordList.push_back(pair);
        }
    }

    for (size_t i = 0; i < wordList.size(); ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < wordList.size(); ++j) {
            if (wordList[j].second < wordList[minIndex].second || 
               (wordList[j].second == wordList[minIndex].second && wordList[j].first < wordList[minIndex].first)) {
                minIndex = j; 
            }
        }
        std::swap(wordList[i], wordList[minIndex]);
    }

    for (const auto& pair : wordList) {
        out << pair.first << "," << pair.second << "\n";
    }
}


void WordCount::addAllWords(std::string text) {
    std::string word;
    std::istringstream stream(text);

    while (stream >> word) {
        word = makeValidWord(word);
        if (!word.empty()) {
            incrWordCount(word); 
        }
    }
}
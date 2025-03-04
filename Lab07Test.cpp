#include <cassert>
#include <iostream>
#include "tddFuncs.h"
#include "WordCount.h"
#include <vector>

using namespace std;
/*JUST REALIZED WE PROBABLY DON'T NEED LAB06 TEST CASES*/


/* THE CODE TESTCASES FROM LAB07TEST*/



/*What type of inputs do we need to test?
*/
void test_dumpWordsSortedByWord() {
    WordCount wc;
    wc.addAllWords("Balls dog dog balls");

    std::ostringstream out;
    wc.dumpWordsSortedByWord(out);
    
    std::string expected = "dog,2\nballs,2\n";
    std::string result = out.str();

    std::cout << "Test 1 - dumpWordsSortedByWord: " << (result == expected ? "PASSED" : "FAILED") << "\n";
}

void test_dumpWordsSortedByOccurence() {
    WordCount wc;
    wc.addAllWords("Balls dog dog balls dog");

    std::ostringstream out;
    wc.dumpWordsSortedByOccurence(out);
    
    std::string expected = "balls,2\ndog,3\n";
    std::string result = out.str();

    std::cout << "Test 2 - dumpWordsSortedByOccurence: " << (result == expected ? "PASSED" : "FAILED") << "\n";
}

void test_addAllWords_basic() {
    WordCount wc;
    wc.addAllWords("Balls dog balls");

    bool passed = (wc.getWordCount("balls") == 2 && wc.getWordCount("dog") == 1);
    std::cout << "Test 3 - addAllWords (basic case): " << (passed ? "PASSED" : "FAILED") << "\n";
}

void test_addAllWords_specialCharacters() {
    WordCount wc;
    wc.addAllWords("Dog's balls-balls dog.");

    bool passed = (wc.getWordCount("dog's") == 1 && 
                   wc.getWordCount("balls-balls") == 1 && 
                   wc.getWordCount("dog") == 1);
                   
    std::cout << "Test 4 - addAllWords (special characters): " << (passed ? "PASSED" : "FAILED") << "\n";
}

void test_addAllWords_whitespace() {
    WordCount wc;
    wc.addAllWords("  dog   balls\n\nballs\t dog  ");

    bool passed = (wc.getWordCount("dog") == 2 &&
                   wc.getWordCount("balls") == 2);
    
    std::cout << "Test 5 - addAllWords (whitespace handling): " << (passed ? "PASSED" : "FAILED") << "\n";
}

void test_addAllWords_caseInsensitivity() {
    WordCount wc;
    wc.addAllWords("DOG dog Dog dOg");

    bool passed = (wc.getWordCount("dog") == 4);
    
    std::cout << "Test 6 - addAllWords (case insensitivity): " << (passed ? "PASSED" : "FAILED") << "\n";
}



int main() {
    // basicInsertTest();
    // caseSensitivityTest();
    // incrementWordTest();
    // emptyStringTest();
    // invalidWordTest();
    // hyphenAndApostTest();
    // largeInputTest1();
    // largeInputTest2();
    //* DELETE LATER RYAN THESE ARE FROM LAB6
/******************************************************* */
    /*LAB07A TEST FUNCTION CALLS */
void test_dumpWordsSortedByWord() {
    WordCount wc;
    wc.addAllWords("Balls dog dog balls");

    std::ostringstream out;
    wc.dumpWordsSortedByWord(out);
    
    std::string expected = "dog,2\nballs,2\n";
    std::string result = out.str();

    std::cout << "Test 1 - dumpWordsSortedByWord: " << (result == expected ? "PASSED" : "FAILED") << "\n";
}

void test_dumpWordsSortedByOccurence() {
    WordCount wc;
    wc.addAllWords("Balls dog dog balls dog");

    std::ostringstream out;
    wc.dumpWordsSortedByOccurence(out);
    
    std::string expected = "balls,2\ndog,3\n";
    std::string result = out.str();

    std::cout << "Test 2 - dumpWordsSortedByOccurence: " << (result == expected ? "PASSED" : "FAILED") << "\n";
}

void test_addAllWords_basic() {
    WordCount wc;
    wc.addAllWords("Balls dog balls");

    bool passed = (wc.getWordCount("balls") == 2 && wc.getWordCount("dog") == 1);
    std::cout << "Test 3 - addAllWords (basic case): " << (passed ? "PASSED" : "FAILED") << "\n";
}

void test_addAllWords_specialCharacters() {
    WordCount wc;
    wc.addAllWords("Dog's balls-balls dog.");

    bool passed = (wc.getWordCount("dog's") == 1 && 
                   wc.getWordCount("balls-balls") == 1 && 
                   wc.getWordCount("dog") == 1);
                   
    std::cout << "Test 4 - addAllWords (special characters): " << (passed ? "PASSED" : "FAILED") << "\n";
}

void test_addAllWords_whitespace() {
    WordCount wc;
    wc.addAllWords("  dog   balls\n\nballs\t dog  ");

    bool passed = (wc.getWordCount("dog") == 2 &&
                   wc.getWordCount("balls") == 2);
    
    std::cout << "Test 5 - addAllWords (whitespace handling): " << (passed ? "PASSED" : "FAILED") << "\n";
}

void test_addAllWords_caseInsensitivity() {
    WordCount wc;
    wc.addAllWords("DOG dog Dog dOg");

    bool passed = (wc.getWordCount("dog") == 4);
    
    std::cout << "Test 6 - addAllWords (case insensitivity): " << (passed ? "PASSED" : "FAILED") << "\n";
}
    

    return 0;
}
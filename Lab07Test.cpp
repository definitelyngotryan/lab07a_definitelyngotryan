#include <cassert>
#include <iostream>
#include "tddFuncs.h"
#include "WordCount.h"
#include <vector>
#include <sstream>

using namespace std;
/*JUST REALIZED WE PROBABLY DON'T NEED LAB06 TEST CASES*/


/* THE CODE TESTCASES FROM LAB07TEST*/



/*What type of inputs do we need to test?
*/


//for some reason this is printing after make lab07test as Test 1 ____ passed, vs. Passed: Test x _____< I am tired solve this later in lab07 
//also make sure u do laundry tmrw morning ryan.
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

    assertEquals(wc.getWordCount("balls"), 2, "Test 3: Word count for 'balls' should be 2.", __LINE__);
    assertEquals(wc.getWordCount("dog"), 1, "Test 4: Word count for 'dog' should be 1.", __LINE__);
}

void test_addAllWords_specialCharacters() {
    WordCount wc;
    wc.addAllWords("Dog's balls-balls dog.");

    assertEquals(wc.getWordCount("dog's"), 1, "Test 5: Word count for 'dog's' should be 1.", __LINE__);
    assertEquals(wc.getWordCount("balls-balls"), 1, "Test 6: Word count for 'balls-balls' should be 1.", __LINE__);
    assertEquals(wc.getWordCount("dog"), 1, "Test 7: Word count for 'dog' should be 1.", __LINE__);
}

void test_addAllWords_whitespace() {
    WordCount wc;
    wc.addAllWords("  dog   balls\n\nballs\t dog  ");

    assertEquals(wc.getWordCount("dog"), 2, "Test 8: Word count for 'dog' should be 2.", __LINE__);
    assertEquals(wc.getWordCount("balls"), 2, "Test 9: Word count for 'balls' should be 2.", __LINE__);
}

void test_addAllWords_caseInsensitivity() {
    WordCount wc;
    wc.addAllWords("DOG dog Dog dOg");

    assertEquals(wc.getWordCount("dog"), 4, "Test 10: Word count for 'dog' should be 4.", __LINE__);
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
    test_dumpWordsSortedByWord();
    test_dumpWordsSortedByOccurence();
    test_addAllWords_basic();
    test_addAllWords_specialCharacters();
    test_addAllWords_whitespace();
    test_addAllWords_caseInsensitivity();
    return 0;
}
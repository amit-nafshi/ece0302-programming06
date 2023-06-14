/**
 * @file FindPalindrome.cpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Project 2: Palindromes
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) 
	{
		value[i] = tolower(value[i]);
	}
}

// helper function to check if a word is valid
static bool isValidWord(const string& word)
{
    for (char c : word) // range based for loop, check through each character in word
	{
        if (!isalpha(c)) // isalpha - check if in alphabet
		{
            return false;
        }
    }
    return true;
}

// helper function to count frequency of each char in a string
// needed for cutTest1, prepares vectors to be checked for palindrome
static vector<int> charCounter(const string& word)
{
    vector<int> charCount(26, 0); // vector covers all letters in alphabet (a-z)
    for (char c : word)
    {
        tolower(c);           // convert char to lowercase 
        charCount[c - 'a']++; // subtracting by 'a' shifts the range from int <0,26> to ASCII <'a','z'>
    }
    return charCount; // send to cut test for further testing
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// test currentStringVector if empty 
	if (currentStringVector.empty()) 
	{
		// create a sentence by concatenating candidateStringVector 
        std::string sentence;
        for (const std::string& word : candidateStringVector) 
		{
            sentence += word;
        }
		// check if palindrome
        if (isPalindrome(sentence)) 
		{
            paliCount++; 								// update count 
            paliVec.push_back(candidateStringVector);	// update vector
        }
        return;
    }

	// recursive loop to generate all possible combinations of words
	for (size_t i = 0; i < currentStringVector.size(); i++) 
	{
		vector<string> newCandidateStringVector = candidateStringVector;
		vector<string> newCurrentStringVector = currentStringVector;

		// add word from currentStringVector to candidateStringVector
		newCandidateStringVector.push_back(currentStringVector[i]);
		
		// remove word from currentStringVector
		newCurrentStringVector.erase(newCurrentStringVector.begin() + i);

		// recursive call
		recursiveFindPalindromes(newCandidateStringVector, newCurrentStringVector);
	}
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	// constructor
	paliCount = 0;
}

FindPalindrome::~FindPalindrome()
{
	// deconstruct through clearing
	clear();
}

int FindPalindrome::number() const
{
	// return palindrome count
	return paliCount;
}

void FindPalindrome::clear()
{
	// clear palindrome
	words.clear(); // built in std function clear, no recursion
	paliCount = 0;
	paliVec.clear();
}

bool FindPalindrome::cutTest1(const vector<string>& stringVector)
{
    vector<int> charCount(26, 0);  // vector covers all letters in alphabet (a-z)

    // count characters in each string in stringVector
    // use charCounter helper function
    for (const string& word : stringVector) 
    {
        vector<int> wordCharCount = charCounter(word);
        for (int i = 0; i < 26; i++) 
        {
            charCount[i] += wordCharCount[i];
        }
    }

    // check if (at most) one character has odd count
    int oddCount = 0;
    for (int count : charCount)
    {
        if (count % 2 == 1) // modulus checks if odd
        {
            oddCount++;
            if (oddCount > 1) 
            {
                return false; // cut test is false, no palindrome
            }
        }
    }
    return true; // pass cut test
}


bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value)
{
	// check if the word is valid (isalpha)
    if (!isValidWord(value)) 
	{
        return false;
    }

	// convert the word to lowercase
    string lowerVal = value;
    convertToLowerCase(lowerVal);

	// check if the lowercase word already exists in the word list
    for (const string& w : words)
    {
        string lowerWord = w;
        convertToLowerCase(lowerWord);

        if (lowerWord == lowerVal)
        {
            return false;
        }
    }

	// add the lowercase word to word list
    words.push_back(lowerVal);

    // clear the palindrome count and vector
    paliCount = 0;
    paliVec.clear();

    // call recursive function to find new palindromes
    recursiveFindPalindromes({}, words);

    return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// loop through vector to check if any word is valid
    for (const string& wrld : stringVector)
    {

		// check if the word is valid (isalpha)
        if (!isValidWord(wrld)) 
		{
            return false;
        }

		// convert the word to lowercase
        std::string lowWord = wrld;
        convertToLowerCase(lowWord);

        for (const string& existingWord : words)
        {
            string lowerExistingWord = existingWord;
            convertToLowerCase(lowerExistingWord);

            if (lowerExistingWord == lowWord)
            {
                return false;
            }
        }
    }


	// add the lowercase words to the word list
	for (const string& vect : stringVector)
    {
        std::string lcWord = vect;
        convertToLowerCase(lcWord);
        words.push_back(lcWord);
    }
	
	// clear the palindrome count and vector
    paliCount = 0;
    paliVec.clear();

    // call recursive function to find new palindromes
    recursiveFindPalindromes({}, words);

    return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// return palidrome vector 
	return paliVec;
}

//********************************************************************************************************
// SOURCES
//********************************************************************************************************
// https://stackoverflow.com/questions/52281172/subtracting-ascii-character-values-in-c
// - charCount range type conversion
// https://code4coding.com/c-program-to-count-the-total-number-of-characters-in-the-given-string-2/
// - use of a vector size of alphabet (case-insensitive) to count each character in a string
// https://stackoverflow.com/questions/8362572/check-if-a-string-is-palindrome
// - helped give me a slightly better understanding of palindrome tests in c++
// https://cplusplus.com/reference/cctype/isalpha/
// - tried looking up what locale does, ended up finding this website that helps check
//   if a word is valid before checking if it is a palindrome
//
//********************************************************************************************************
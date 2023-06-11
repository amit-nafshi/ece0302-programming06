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
    for (char c : word) // loops through each character in word
	{
        if (!isalpha(c)) // isalpha check if in alphabet
		{
            return false;
        }
    }
    return true;
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// test currentStringVector if empty 
	if (currentStringVector.empty()) 
	{
		// test for palindrome in candidateStringVector 
        std::string sentence;
        for (const std::string& word : candidateStringVector) {
            sentence += word;
        }
        if (isPalindrome(sentence)) {
            ++paliCount; 								// update count 
            paliVec.push_back(candidateStringVector);	// update vector
        }
        return;
    }


	// recursive loop
	for (size_t i = 0; i < currentStringVector.size(); i++) 
	{
		vector<string> newCandidateStringVector = candidateStringVector;
		vector<string> newCurrentStringVector = currentStringVector;

		// add word from currentStringVector to candidateStringVector
		newCandidateStringVector.push_back(currentStringVector[i]);
		
		// remove word from currentStringVector
		newCurrentStringVector.erase(newCurrentStringVector.begin() + i);

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

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
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
    for (size_t i = 0; i < words.size(); i++) 
	{
        std::string lcWord = words[i];
        convertToLowerCase(lcWord);
        if (lcWord == lowerVal) {
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
	for (size_t i = 0; i < stringVector.size(); i++) 
	{
        const std::string& word = stringVector[i];

		// check if the word is valid (isalpha)
        if (!isValidWord(word)) 
		{
            return false;
        }

		// convert the word to lowercase
        std::string lowWord = word;
        convertToLowerCase(lowWord);

        for (size_t j = 0; j < words.size(); j++) 
		{
            const std::string& existingWord = words[j];
            std::string lcExist = existingWord;
            convertToLowerCase(lcExist);
            
            if (lcExist == lowWord) 
			{
                return false;
            }
        }
    }


	// add the lowercase words to the word list
	for (size_t z = 0; z < stringVector.size(); z++) 
	{
        const std::string& vect = stringVector[z];
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


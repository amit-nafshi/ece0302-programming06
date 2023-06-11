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
	// TODO need to implement this recursive function!
	return;
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
	// TODO need to implement this...
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

	// add the lowercase word to word list
    words.push_back(lowerVal);

    // Clear the palindrome count and solutions vector
    paliCount = 0;
    paliVec.clear();

    // Call the recursive function to find new palindromes
    recursiveFindPalindromes({}, words);

    return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	return paliVec;
}


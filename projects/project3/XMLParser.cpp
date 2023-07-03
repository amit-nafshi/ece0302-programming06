// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	elementNameBag = new Bag<std::string>();
    parseStack = new Stack<std::string>();
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	delete elementNameBag;
    delete parseStack;
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	std::string token;
    bool inTag = false;
    bool isEmptyTag = false;

    // Clear the vector before tokenizing a new input string
    tokenizedInputVector.clear();

    // Iterate through each character in the input string
    for (size_t i = 0; i < inputString.size(); ++i) {
        char ch = inputString[i];

        if (ch == '<') { // If start of a tag
            inTag = true;

            // Check if this is a declaration tag
            if (i + 1 < inputString.size() && inputString[i + 1] == '?') {
                isEmptyTag = true;
                ++i; // skip the '?' character
            }

            // If there were contents before this tag, store them as CONTENT
            if (!token.empty()) {
                TokenStruct contentToken;
                contentToken.tokenType = CONTENT;
                contentToken.tokenString = token;
                tokenizedInputVector.push_back(contentToken);
                token.clear();
            }

        } else if (ch == '>') { // If end of a tag
            inTag = false;

            // Determine the type of the tag
            StringTokenType tokenType;
            if (isEmptyTag) {
                tokenType = DECLARATION;
                isEmptyTag = false;
            } else if (token[0] == '/') {
                tokenType = END_TAG;
            } else if (token[token.size() - 1] == '/') {
                tokenType = EMPTY_TAG;
            } else {
                tokenType = START_TAG;
            }

            TokenStruct tagToken;
            tagToken.tokenType = tokenType;
            tagToken.tokenString = token;
            tokenizedInputVector.push_back(tagToken);
            token.clear();

        } else if (inTag) { // If within a tag, append the character to token
            token += ch;
        } else { // If within content, append the character to token
            token += ch;
        }
    }    

    return true;
}  // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	if (tokenizedInputVector.empty()) 
	{
        return false;
    }
    
    // Clear the parseStack
    while (!parseStack->isEmpty()) 
	{
        parseStack->pop();
    }
    
    for (const auto &tokenStruct : tokenizedInputVector) 
	{
        if (tokenStruct.tokenType == START_TAG) 
		{
            parseStack->push(tokenStruct.tokenString);
        } else if (tokenStruct.tokenType == END_TAG) 
		{
            // If the stack is empty or the end tag doesn't match the top of the stack, return false
            if (parseStack->isEmpty() || tokenStruct.tokenString != parseStack->peek()) 
			{
                return false;
            }
            parseStack->pop();
        }
    }
    
    // If the stack is not empty, it means that there are unmatched start tags
    return parseStack->isEmpty();
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	elementNameBag->clear();
    parseStack->clear();
    tokenizedInputVector.clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	if (tokenizedInputVector.empty() || parseStack != nullptr) 
	{
        throw std::logic_error("Input has not been tokenized and parsed");
    }
    return elementNameBag->contains(inputString);
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if (tokenizedInputVector.empty() || parseStack != nullptr) 
	{
        throw std::logic_error("Input has not been tokenized and parsed.");
    }
    return elementNameBag->getFrequencyOf(inputString);
}


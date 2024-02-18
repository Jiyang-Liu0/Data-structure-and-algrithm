#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"
#include <algorithm>
#include <sstream>
#include <unordered_map>


using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

static bool isAlphabet(const string & value)
{
	for (char c : value) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
	return true;
}

static bool hasSameElement(string value, const vector<string> currentStringVector)
{
	for (string str:currentStringVector)
	{
		convertToLowerCase(str);
		convertToLowerCase(value);
		if (str == value)
		{
			return true;
		}
	}
	return false;
}
//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	if (currentStringVector.size()==0)
	{
		std::stringstream ss;

    	for(const auto& str : candidateStringVector) {
        	ss << str;
    	}

    	std::string concatenatedString = ss.str();

		if (isPalindrome(concatenatedString))
		{
			candidateStringVectors.push_back(candidateStringVector);
		}
		
		return;
	}

	for (string str:currentStringVector)
	{	
		vector<string> nextCandidateVector = candidateStringVector;
		vector<string> nextStringVector = currentStringVector;
		nextCandidateVector.push_back(str);
		nextStringVector.erase(std::remove(nextStringVector.begin(), nextStringVector.end(), str));
		recursiveFindPalindromes(nextCandidateVector, nextStringVector);
	}
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
	
}

FindPalindrome::~FindPalindrome()
{
	currentStringVector.clear();
	candidateStringVectors.clear();
}

int FindPalindrome::number() const
{
	return candidateStringVectors.size();
}

void FindPalindrome::clear()
{
	currentStringVector.clear();
	candidateStringVectors.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
    std::unordered_map<char, int> charCounts;

    for (const auto& str : stringVector) {
        for (char c : str) {
            charCounts[c]++;
        }
	}
	
	int oddCount = 0;
    for (const auto& pair : charCounts) {
        if(pair.second%2 == 1)
		{
			oddCount ++;
		}
    }

	if (oddCount > 1)
	{
		return false;
	}

	return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	int vec1Length = 0, vec2Length = 0;
	std::unordered_map<char, int> charCounts1;
    std::unordered_map<char, int> charCounts2;

	for (const auto& str : stringVector1) {
		vec1Length += str.size();
		for (char c : str) {
            charCounts1[c]++;
        }
	}

	for (const auto& str : stringVector2) {
		vec2Length += str.size();
		for (char c : str) {
            charCounts2[c]++;
        }
	}

	if (vec1Length<=vec2Length)
	{
		for (const auto &pair:charCounts1)
		{
			if (charCounts2.count(pair.first)==0)
			{
				return false;
			}
		}
	}else{
		for (const auto &pair:charCounts2)
		{
			if (charCounts1.count(pair.first)==0)
			{
				return false;
			}
		}
	}

	return true;

}

bool FindPalindrome::add(const string & value)
{
	if (!isAlphabet(value))
	{
		return false;
	}

	if (hasSameElement(value,currentStringVector))
	{
		return false;
	}
	
	currentStringVector.push_back(value);
	vector<string> candidateStringVector;
	candidateStringVectors.clear();
	recursiveFindPalindromes(candidateStringVector, currentStringVector);
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	for(string str:stringVector)
	{
		if (!isAlphabet(str))
		{
			return false;
		}

		if (hasSameElement(str,currentStringVector))
		{
			return false;
		}
	}

	for(string str:stringVector)
	{
		currentStringVector.push_back(str);
	}
	vector<string> candidateStringVector;
	candidateStringVectors.clear();
	recursiveFindPalindromes(candidateStringVector, currentStringVector);

	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	return candidateStringVectors;
}
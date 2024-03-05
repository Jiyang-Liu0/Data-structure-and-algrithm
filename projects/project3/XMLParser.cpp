// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

XMLParser::XMLParser() :isParseSuccess(false)
{
	elementNameBag=new Bag<std::string>();
	parseStack=new Stack<std::string>();
	
}  // end default constructor

XMLParser::~XMLParser()
{
	delete elementNameBag;
	delete parseStack;
}  // end destructor

std::string XMLParser::extractTagName(const std::string &str)
{
	for(int i=0;i<str.size();i++)
	{
		if(std::isspace(str[i]))
		{
			return str.substr(0,i);
		}
	}
	return str;
}

std::string XMLParser::trim(const std::string &str) {
	size_t start = 0;
    size_t end = str.length() - 1;

    // Find the position of the first non-space character from the beginning
    while (start <= end && std::isspace(str[start])) {
        start++;
    }

    // Find the position of the first non-space character from the end
    while (end >= start && std::isspace(str[end])) {
        end--;
    }

    // Return the substring without leading and trailing spaces
    return str.substr(start, end - start + 1);
}

bool XMLParser::isNotValidName(const std::string &str)
{
	std::string invalidStr="!\"#$%&'()*+,/;<=>?@[\\]^`{|}~";

	for(int i=0;i<str.size();i++)
	{
		if(invalidStr.find(str[i])!=std::string::npos)
		{
			std::cerr << "Find invalid char as " << str[i] << " in " << str << std::endl;
			return true;
		}
	}

	if(std::isdigit(str[0]) || str[0]=='-' ||str[0]=='.')
	{
		// std::cerr << "Invalid input: Missing closing '?>'" << std::endl;
		std::cerr << "Find invalid char as " << str[0] << " in the begin of " << str << std::endl;
		return true;
	}

	return false;
}

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	std::size_t start=0, end=0,pos=0;
	pos = inputString.find('<', start);
	while (pos!=std::string::npos)
	{

		end = inputString.find('>', pos);
		if(end == std::string::npos)
		{
			clear();
			return false;
		}
		
		if (start<pos)
		{
			std::string tokenStr=inputString.substr(start,pos-start+1-1);
			tokenStr = trim(tokenStr);
			if (tokenStr.length()>0) {
				TokenStruct tokenStruct={StringTokenType::CONTENT,tokenStr};
				tokenizedInputVector.push_back(tokenStruct);
			}
		}
		//"<test>stuff</test>" "<empty/>"
		//"<?xml version=\"1.0\" encoding=\"UTF-8\"?><Note src='gmail'>  <From>Tom</From> <To>Alice</To> </Note>"
		if(inputString[pos+1]=='?')
		{
			if(inputString[end-1]!='?')
			{
				clear();
				return false;
			}
			std::string tokenStr=inputString.substr(pos+2,end-pos+1-4);
			TokenStruct tokenStruct={StringTokenType::DECLARATION,tokenStr};
			tokenizedInputVector.push_back(tokenStruct);
		} else if(inputString[pos+1]=='/')
		{
			std::string tokenStr=inputString.substr(pos+2,end-pos+1-3);
			if(isNotValidName(tokenStr))
			{
				clear();
				return false;
			}
			TokenStruct tokenStruct={StringTokenType::END_TAG,tokenStr};
			tokenizedInputVector.push_back(tokenStruct);
		} else if(inputString[end-1]=='/')
		{
			std::string tokenStr=inputString.substr(pos+1,end-pos+1-3);
			tokenStr=extractTagName(tokenStr);
			if(isNotValidName(tokenStr))
			{
				clear();
				return false;
			}
			TokenStruct tokenStruct={StringTokenType::EMPTY_TAG,tokenStr};
			tokenizedInputVector.push_back(tokenStruct);
		} else
		{
			std::string tokenStr=inputString.substr(pos+1,end-pos+1-2);
			tokenStr=extractTagName(tokenStr);
			if(isNotValidName(tokenStr))
			{
				clear();
				return false;
			}
			TokenStruct tokenStruct={StringTokenType::START_TAG,tokenStr};
			tokenizedInputVector.push_back(tokenStruct);
			elementNameBag->add(tokenStr);
		}


		if(end==inputString.size())
		{
			break;
		}
		start=end+1;
		pos = inputString.find('<', start);
	}


	return true;
}  

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	for (size_t i = 0; i < tokenizedInputVector.size(); ++i) {
        if(tokenizedInputVector[i].tokenType==StringTokenType::START_TAG)
		{
			parseStack->push(tokenizedInputVector[i].tokenString);
		}else if(tokenizedInputVector[i].tokenType==StringTokenType::END_TAG)
		{
			if(parseStack->peek()==tokenizedInputVector[i].tokenString)
			{
				parseStack->pop();
			}else{
				parseStack->clear();
				return false;
			}
		}
    }

	isParseSuccess=true;
	return true;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	elementNameBag->clear();
	parseStack->clear();
	tokenizedInputVector.clear();
	isParseSuccess=false;
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	if(!isParseSuccess)
	{
		throw std::logic_error("There is logic error");
	}

	return elementNameBag->contains(inputString);
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if(!isParseSuccess)
	{
		throw std::logic_error("There is logic error");
	}

	return elementNameBag->getFrequencyOf(inputString);
}


#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {

  if (postfix.length() == 1) {
    prefix = postfix;
  } else {
    char op = postfix[postfix.length()-1]; // should start with an operator
    int endFirst = endPost(postfix, postfix.length()-2);
    string operand1;
    string tempStr1 = postfix.substr(endFirst, postfix.length()-2-endFirst+1);
    convert(tempStr1, operand1);

    int endSecond = endPost(postfix, endFirst-1);
    string operand2;
    string tempStr2 = postfix.substr(endSecond, endFirst-endSecond);
    convert(tempStr2, operand2);
    prefix = op + operand2 + operand1;
  }
  
}

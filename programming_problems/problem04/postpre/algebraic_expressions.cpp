#include <string>
using std::string;

#include <iostream>
#include <stack>
#include <string>
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

void convert(string &postfix, string &prefix) 
{
  // 5.2.3 (Inverse!)
  // post to pre
  std::stack<std::string> stack;
  for (char ch : postfix) 
  {
    if (isalpha(ch)) 
    {  
      // operand
      std::string operand(1, ch);
      stack.push(operand);
    } 
    else 
    {  
      // operator
      std::string operand2 = stack.top();
      stack.pop();
      std::string operand1 = stack.top();
      stack.pop();

      std::string result = ch + operand1 + operand2;
      stack.push(result);
    }
  }

  prefix = stack.top();
}


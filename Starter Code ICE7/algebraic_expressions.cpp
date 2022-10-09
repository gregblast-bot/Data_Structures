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
  
    // Get the length of the postfix expression 
    int length = postfix.length();
    //unsigned int count = 0; // Needed for old implementation
    // Set this temp variable to the last variable
	char temppost = postfix[length-1]; 
	
	// If the index of the postfix expression is alphabetical, add to prefix
	if(isalpha(temppost)){
		// Make sure to perform addition operation this way to append
		prefix = temppost + prefix;
		//std::cout << "temp:" << prefix << std::endl; Check temp
	}
		
	// Else fall into tis process
	else{
		// Get the end of the postfix using the endPost member function
		int endfirst = endPost(postfix, length-2);
		//std::cout << "endfirst:" << endfirst << std::endl; Check endPost
		
		// Create to temporary postfix substrings to use in a recursive conversion
		string post1 = postfix.substr(endfirst, length-1);
		string post2 = postfix.substr(0, endfirst);
		
		//std::cout << "post1:" << post1 << std::endl; Check post1
		//std::cout << "post2:" << post2 << std::endl; Check post2
		
		// Create another temp variable to push into the conversion recursion
		int length1 = post1.length();
		string post3 = post1.substr(0, length1-1);
		
		
		// Recursive conversion call and add to prefix the temporary postfix
		convert(post3, prefix);
		convert(post2, prefix);
		
		prefix = temppost + prefix;
	}
	
	// For old implementation, doesn't work now
	/*count++;
		
	if(isalpha(temppost) && !isoperator(temppost)){
		for(unsigned int i = count; i < postfix.length(); i++){
			string test = postfix.substr(i, length-1);
			std::cout << "prefix:" << prefix << std::endl << "length" << length << std::endl;
			convert(test, prefix);
		}
	}*/
}

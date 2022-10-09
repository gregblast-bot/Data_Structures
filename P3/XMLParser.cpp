// Project 3 -- XML Parsing Project
// Gregory Wagonblast

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include "XMLParser.hpp"

// Default constructor, dynamically instantiate our bag and stack pointers.
// Initialize our vector to an empty vector.
XMLParser::XMLParser()
{
	elementNameBag = new Bag<std::string>;
	parseStack = new Stack<std::string>;
	tokenizedInputVector = {};
}  // end default constructor

// Destructor, destroy using the this operator and the clear functions for ease.
XMLParser::~XMLParser()
{
	this -> clear();
}  // end destructor

/* This static function cleans up the left overs of the temporary string
 * used in the following function. */
static std::string deleteAttributes(std::string input)
{
	// Clean up and erase the leftovers from the temporary string
	for(std::size_t z = 0; z <= input.length(); z++){
		input.erase(z);
	}
	
	// Return the cleaned up string, ideally it will be empty
	return input;
}

// TODO: Implement the tokenizeInputString method, oh yeah
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	// Store inputString in a temporary string so we can manipulate the text 
	std::string tempString = inputString;
	// Instantiate all varaibles to be used
	std::string tokenStringDeclaration1, tokenStringDeclaration2, tokenStringEmpty1, tokenStringEmpty2; 
	std::string tokenStringStart1, tokenStringStart2, tokenStringEnd1, tokenStringEnd2, tokenStringContent;
	char newline = '\n';
	std::size_t found, empty, space;
	
	// Check if the text file is empty and return false if yes
	if(tempString.empty() == true){
		std::cout << "Text file is empty!" << std::endl;
		return false;
	}
	
	// Use the erase remove idiom in order to remove all newlines from the string
	tempString.erase(remove(tempString.begin(), tempString.end(), newline), tempString.end());
	
	// Search the text file
	for(std::size_t i = 0; i < tempString.length(); i++){
		
		// If we find a declaration, fall into this case
		if(tempString[i] == '<' && tempString[i+1] == '?'){
			// Initialize strings as empty
			tokenStringDeclaration1 = "";
			tokenStringDeclaration2 = "";
			
			/* Find the index of the beginning of the end of the declaration
			 * and also the whitespace, i+2 means that we ignore errthing before i+2*/
			found = tempString.find("?>", i+2);
			space = tempString.find(' ', i+2);
			
				// If found comes before the whitespace, fall into this case
				if(found < space){
					// For j = i+2 until the character before found, collect string into declaration
					for(std::size_t j = i+2; j < found; j++){
						tokenStringDeclaration1 += tempString[j];
					}
					// Set tokenType and tokenString, push back on vector and store in bag
					_TokenStruct_ tokenDeclaration;
					tokenDeclaration.tokenType = DECLARATION;
					tokenDeclaration.tokenString = tokenStringDeclaration1;
					tokenizedInputVector.push_back(tokenDeclaration);
					elementNameBag -> add(tokenStringDeclaration1);
				}
				// If whitespace comes before the found, fall into this case
				else if(space < found){
					for(std::size_t r = i+2; r < space; r++){
						tokenStringDeclaration2 += tempString[r]; 
					}
					// Set tokenType and tokenString, push back on vector and store in bag
					_TokenStruct_ tokenDeclaration;
					tokenDeclaration.tokenType = DECLARATION;
					tokenDeclaration.tokenString = tokenStringDeclaration2;
					tokenizedInputVector.push_back(tokenDeclaration);
					elementNameBag -> add(tokenStringDeclaration2);
				}
			
			// Erase from temporary string, length plus brackets
			tempString.erase(i, tokenStringDeclaration1.length()+3);
		}
		
		// If we find an end tag, fall into this case
		else if(tempString[i] == '<' && tempString[i+1] == '/'){ 
			// Initialize strings as empty	
			tokenStringEnd1 = "";
			tokenStringEnd2 = "";
			
			/* Find the index of the beginning of the end of the declaration
			 * and also the whitespace, i+2 means that we ignore errthing before i+2*/
			found = tempString.find('>', i+2);
			space = tempString.find(' ', i+2);
			
				// If found comes before the whitespace, fall into this case
				if(found < space){
					// For k = i+2 until the character before found, collect string into end tag
					for(std::size_t k = i+2; k < found; k++){
						tokenStringEnd1 += tempString[k]; 
					}
					// Set tokenType and tokenString, push back on vector and store in bag
					_TokenStruct_ tokenEnd;
					tokenEnd.tokenType = END_TAG;
					tokenEnd.tokenString = tokenStringEnd1;
					tokenizedInputVector.push_back(tokenEnd);
					elementNameBag -> add(tokenStringEnd1);
				}
				// If whitespace comes before the found, fall into this case
				else if(space < found){
					for(std::size_t q = i+2; q < space; q++){
						tokenStringEnd2 += tempString[q]; 
					}
					// Set tokenType and tokenString, push back on vector and store in bag
					_TokenStruct_ tokenEnd;
					tokenEnd.tokenType = END_TAG;
					tokenEnd.tokenString = tokenStringEnd2;
					tokenizedInputVector.push_back(tokenEnd);
					elementNameBag -> add(tokenStringEnd2);
				}
			
			// Erase from temporary string, length plus brackets
			tempString.erase(i, tokenStringEnd1.length()+2);
		}
		
		// If we find the begginning angle bracket, fall into this case
		else if(tempString[i] == '<' && tempString[i+1] != '/' && tempString[i+1] != '?'){
		
			// Find the index of the beginning of the empty of the empty tag
			// i+2 means that we ignore errthing before i+2
			empty = tempString.find("/>", i+2);
			found = tempString.find('>', i+2);	
			space = tempString.find(' ', i+2);
			
			// If the empty indicator is correct and empty comes before found, fall into this case
			if(tempString[empty] == '/' && (empty < found)){
				// Initialize strings as empty
				tokenStringEmpty1 = ""; 
				tokenStringEmpty2 = ""; 
				
				// If found comes before the whitespace, fall into this case
				if(found < space){
					// For l = i+1 until the character before found, collect string into empty tag
					for(std::size_t l = i+1; l < empty; l++){
						tokenStringEmpty1 += tempString[l]; 
					}
					// Set tokenType and tokenString, push back on vector and store in bag
					_TokenStruct_ tokenEmpty;
					tokenEmpty.tokenType = EMPTY_TAG;
					tokenEmpty.tokenString = tokenStringEmpty1;
					tokenizedInputVector.push_back(tokenEmpty);
					elementNameBag -> add(tokenStringEmpty1);
				}
				// If whitespace comes before the found, fall into this case
				else if(space < found){
					for(std::size_t p = i+1; p < space; p++){
						tokenStringEmpty2 += tempString[p]; 
					}
					// Set tokenType and tokenString, push back on vector and store in bag
					_TokenStruct_ tokenEmpty;
					tokenEmpty.tokenType = EMPTY_TAG;
					tokenEmpty.tokenString = tokenStringEmpty2;
					tokenizedInputVector.push_back(tokenEmpty);
					elementNameBag -> add(tokenStringEmpty2);
				}
				
				// ERROR CHECK, WE GOOD. Erase
				tempString.erase(i, tokenStringEmpty1.length()+2);
			}
			
			// If the found indicator is correct and empty comes after found, fall into this case
			else if(tempString[found] == '>' && (empty > found)){
				// Initialize strings as empty
				tokenStringStart1 = "";
				tokenStringStart2 = "";
				
				// If found comes before the whitespace, fall into this case
				if(found < space){
					// For m = i+1 until the character before found, collect string into empty tag
					for(std::size_t m = i+1; m < found; m++){
						tokenStringStart1 += tempString[m]; 
					}
					// Set tokenType and tokenString, push back on vector and store in bag
					_TokenStruct_ tokenStart;
					tokenStart.tokenType = START_TAG;
					tokenStart.tokenString = tokenStringStart1;
					tokenizedInputVector.push_back(tokenStart);
					elementNameBag -> add(tokenStringStart1);
				}	
				// If whitespace comes before the found, fall into this case
				else if(space < found){
					for(std::size_t o = i+1; o < space; o++){
						tokenStringStart2 += tempString[o]; 
					}
					// Set tokenType and tokenString, push back on vector and store in bag
					_TokenStruct_ tokenStart;
					tokenStart.tokenType = START_TAG;
					tokenStart.tokenString = tokenStringStart2;
					tokenizedInputVector.push_back(tokenStart);
					elementNameBag -> add(tokenStringStart2);
				}
				
				// ERROR CHECK, WE GOOD. Erase
				tempString.erase(i, tokenStringStart1.length()+1);
			}
		}
		
		/* If the an angle bracket comes before the position we are observing
		 * and the "content" is alphanumeric, fall into this case.*/
		else if((tempString[i-1] == '>') && (isalnum(tempString[i]))){
				// Initialize string as empty
				tokenStringContent = "";
				// Find the index of the beginning of the content of the content tag
				// i-1 means that we ignore errthing before i-1
				found = tempString.find('<' , i-1);
				
				// For n = i+1 until the character before found, collect string into empty tag
				for(std::size_t n = i; n < found; n++){
					tokenStringContent += tempString[n]; 
				}
			
				// Set tokenType and tokenString, push back on vector and store in bag
				_TokenStruct_ tokenContent;
				tokenContent.tokenType = CONTENT;
				tokenContent.tokenString = tokenStringContent;
				tokenizedInputVector.push_back(tokenContent);
				elementNameBag -> add(tokenStringContent);
				tempString.erase(i, tokenStringContent.length()-1);
			    
		}
	}
	
	// Delete string leftovers
	tempString = deleteAttributes(tempString);
	
	// Return true upon successful completion of tokenizing
	return true;
	
}  // end

// TODO: Implement the parseTokenizedInput method here, oh boy
bool XMLParser::parseTokenizedInput()
{
	// NOTE: start tag and end tag must match exactly, still working on
	// Initialize variables, notably our string of no-nos
	bool found;
	std::string search1 = "!#$%&'()*+,/;<=>";
	std::string search2 = "?@[]^`{|}\\!#$%&\""; 
	_TokenStruct_ tagName;
	std::string tokenString = "";
	
	// If our bag is empty we cannot parse because there were no elements tokenized
	if(elementNameBag -> isEmpty()){
		std::cout << "No tokens, cannot parse." << std::endl;
		return false;
	}
	
	
	// Search the tags for the first 16 unallowable characters
	for(std::size_t i = 0; i < tokenizedInputVector.size(); i++){
		  // Set the tag to the specific vector string 
		  tagName = tokenizedInputVector.at(i);
		  
		  // If the tag is not content we fall into this case
		  if(tagName.tokenType != CONTENT){
			  // Search the length of the vector string/the non-allowable character string
			  for(std::size_t j = 0; j < search1.length(); j++){
				  // Find if any of our non-allowable characters are present
				  found = std::find(tagName.tokenString.begin(), tagName.tokenString.end(), search1[j]) != tagName.tokenString.end();
				  
				   // If any non-allowable characters are presnt, return false.
				   if(found == true){
					  std::cout << "Bad tag." << std::endl;
					  return false;
				   }
				   
				   // If the first index of the vector string contatins a '-', '.' o numeric digit, return false.
				   if(tagName.tokenString[0] == '-' || tagName.tokenString[0] == '.' || isdigit(tagName.tokenString[0]) == true){
					   std::cout << "Tag cannot start with '-', '.' or a numeric digit." << std::endl;
					   return false;
				   }
			  }
		  }
	  }
		
		// Search the tags for the rest of the unallowable characters
		for(std::size_t i = 0; i < tokenizedInputVector.size(); i++){
			  // Set the tag to the specific vector string 
			  tagName = tokenizedInputVector.at(i);
			  
			  // If the tag is not content we fall into this case
			  if(tagName.tokenType != CONTENT){
				  // Search the length of the vector string/the non-allowable character string
				  for(std::size_t j = 0; j < search2.size(); j++){
					  // Find if any of our non-allowable characters are present
					  found = std::find(tagName.tokenString.begin(), tagName.tokenString.end(), search1[j]) != tagName.tokenString.end();
					  
					   // If any non-allowable characters are presnt, return false.
					  if(found == true){
						 std::cout << "Bad tag." << std::endl;
						 return false;
					  }
					  
					  // If the first index of the vector string contatins a '-', '.' o numeric digit, return false.
					  if(tagName.tokenString[0] == '-' || tagName.tokenString[0] == '.' || isdigit(tagName.tokenString[0]) == true){
					     std::cout << "Tag cannot start with '-', '.' or a numeric digit." << std::endl;
					     return false;
					  }
				  }
			  }
			  
			  // Once all test are complete, push the respective tag onto the stack
			  parseStack -> push(tagName.tokenString);
		}
		
		// While the bag and stack contain elements, loop through them
		while(elementNameBag -> isEmpty() == false && parseStack -> isEmpty() == false){
			// Peek at the head pointer
			std::string result = parseStack -> peek();
			
			// If the bag and stack contain the same elements, we are good to go
			if(elementNameBag -> contains(result) == true){
				return true;
			}
			
			// If not, return false
			else{
				return false;
			}
			
			// Pop off the stack so we don't get caught in an infinite loop
			parseStack -> pop();
		}
	
	// Return true upon successful completion
	return true;
}

// Take advantage of the clear member functions in our bag and stack classes
void XMLParser::clear()
{
	elementNameBag -> clear();
	parseStack -> clear();
}

// Return a vector of the tokenized input
vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// Take advantage of the contains member functions in our bag class
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return (elementNameBag -> contains(inputString));
}

// Take advantage of the getFrequencyOf member functions in our bag class
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return (elementNameBag -> getFrequencyOf(inputString));
}


#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include <algorithm>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited. WE CAN ONLY USE THESE FOR PRIVATE MEMBER FUNCTIONS 

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (unsigned int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

// Check to see if the string is an allowable candidate
static bool allowableVectorCandidate(const vector<string> & stringVector)
{	
	string temp;
	unsigned int count = 0;
	
	// Create a temporary variable to hold the string vector as one whole string
	for(unsigned int i = 0; i < stringVector.size(); i++){
		temp = temp + stringVector.at(i);
	}
	
	// Use isalpha function to check if the string is allowable	
	for(unsigned int i = 0; i < temp.length(); i++){
		
		if(isalpha(temp[i])){
			count++;
		}
	}
	
	// If every character in the string passed, we're good to go	
	if(count == temp.length()){
		return true;
	}
	
	else{
		return false;
	}
}

// Check to see if the string is an allowable candidate
static bool allowableStringCandidate(const string & value)
{
	
	unsigned int count;
	
	// Use isalpha function to check if the string is allowable
	for(unsigned int i = 0; i < value.length(); i++){
		
		if(isalpha(value[i])){
			count++;
		}
	}
	
	// If every character in the string passed, we're good to go	
	if(count == value.length()){
		return true;
	}
	
	else{
		return false;
	}
}

// Remove all spaces and punctuation with isalpha loop
static void sentenceToString(vector<string> & stringVector)
{
	// Create a string vector to hold the result
	vector<string> result;
	
	// Loop through the string vector
	for(unsigned int i = 0; i < stringVector.size(); i++){
		// Create temporary variables to hold the strings at the vector indices
		string temp1 = stringVector.at(i);
		string temp2 = result.at(i);
		
		// Loop through the elements of the string
		for(unsigned int j = 0; j < temp1.length(); j++){
			// If the element is alphabetical, put that value into result
			if(isalpha(temp1[i])){
				temp2[i] = temp1[i];
			}
		}
	}
}

//Checks for duplicate strings using a pre-made algoritm
static void duplicate(vector<string> & stringVector){
	
	// Algorithm for finding duplicates
	sort(stringVector.begin(), stringVector.end());
	vector<string>::iterator it = unique(stringVector.begin(), stringVector.end());
	bool wasUnique = (it == stringVector.end());
	
	if(wasUnique == false){
		cout << "Duplicates are not allowed." << endl;
	}
	
	else{
		cout << "Lookin' good." << endl;
	}
}

// Recursive factorial function for the N! words
static int factorial(int n)
{
	// If n is greater than one do recursive stuff
    if(n > 1){
        return n * factorial(n - 1);
	}
	
	// Else return butt
    else{
        return 1;
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// Check to see if the number of palindromes exceeds N!
	/*if(num > factorial(num)){
		cout << "Too many N words." << endl;
	}*/
	
	// Turn the sentence to a string, don't need this now. Might be useful later
	// sentenceToString(currentStringVector);
	// sentenceToString(candidateStringVector);
	// Check for duplicate strings
	// duplicate(currentStringVector);
	// duplicate(candidateStringVector);
	
	// If the current string vector is empty, fall into this case
	if(currentStringVector.empty() == true){
		string test;
		
		// Turn the string vector into one long string 
		for(unsigned int i = 0; i < candidateStringVector.size(); i++){
			test = test + candidateStringVector.at(i);
		}	
		
			// If candidate string vector passes the palindrome test, fall into this case
			if(isPalindrome(test) == true){
				// Increment the number of palindromes
				num++;
				// Add the candidate string vector to our private palindrome vector
				palindromeVector.push_back(candidateStringVector);
			}
	}
	
	else{
		
		// Loop through the currentStringVector and create temporary variables 
		for(unsigned int i = 0; i < currentStringVector.size(); i++){
			vector<string> temp1 = candidateStringVector;
			vector<string> temp2 = currentStringVector;
			temp2.erase(temp2.begin()+i);
			temp1.push_back(currentStringVector.at(i));
			
			// If current string and candidate string pass cut test 2, do recursion
			if(cutTest2(temp1, temp2) == false){
				recursiveFindPalindromes(temp1, temp2);
			}
		}	
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

/* Default constructor creates an empty vector for storing plaindomes,
 * initializes word to an empty string, num to zero, and truth to false.
 */ 
FindPalindrome::FindPalindrome()
{
	vector<string> palindrome = {};
	vector<string> Empty = {};
	vector<vector<std::string>> palindromeVector = {{}};
	num = 0;
	
}

//Destructor for our vector palindrome, deletes from memory
FindPalindrome::~FindPalindrome()
{
	palindromeString.clear();
	//palindromeString.~vector<string>(); // This was working until the implementation of add(const vector<string> & stringVector)
	//palindromeVector.~vector<vector<string>>; Nope, not havin' it
}

// Return the number of palindromes that have been found
int FindPalindrome::number() const
{
	return num;
}

// Clear the palindrome string and palindrome vector of all elements
// Set the number of palindromes to zero
void FindPalindrome::clear()
{
	palindromeString.clear();
	//palindromeVector.clear();
	num = 0;
}

/* Cut test 1 checks whether the string is even or odd, performs specfic
 * operations based on that and returns a bool value determining if the
 * string vector is viable
 */ 
bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// Initalize variables 
	unsigned int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	
	// Turn the string vector into one long string
	for(unsigned int i = 0; i < stringVector.size(); i++){
		string temp;
		temp = temp + stringVector.at(i);
		
		// Count the length of the string		
		for(unsigned int j = 0; j < temp.length(); j++){
					count1++;
		}
	}	
	
	// If the string vector is even, fall into this case	
	if(count1 % 2 == 0){
		
		string temp;
		locale loc;
		
		// Convert the string vector to one long string
		for(unsigned int i = 0; i < stringVector.size(); i++){
			temp = temp + stringVector.at(i);
		}
		
		for(unsigned int i = 0; i < temp.size(); i++) {
			temp[i] = tolower(temp[i],loc);
		}
			
		// Loop thru to half the length
		for(unsigned int j = 0; j < temp.length()/2; j++){
			char test1 = temp[j];
			char test2 = (temp[temp.length()-1-j]);
		
			// If the jth letter and the lenth-jth letter are equal, continue returning true
			if(test1 == test2){
				count4++;
			}
		}
		
		if(count4 == temp.length()/2){
			return true;
		}
		
		else{
			return false;
		}
	}
	
	// If the string vector is odd, fall into this case
	else{
		
		string temp1;
		locale loc;
		
		// Convert the string vector to one long string
		for(unsigned int i = 0; i < stringVector.size(); i++){
			string temp1;
			temp1 = temp1 + stringVector.at(i);
		}
		
		//Convert string to lower case
		for(unsigned int i = 0; i < temp1.size(); i++) {
			temp1[i] = tolower(temp1[i],loc);
		}
			
		//Loop thru the length of the string
		for(unsigned int j = 0; j < temp1.length(); j++){
		  // Create a char variable to hold the middle letter
		  char temp2;
		  temp2 = temp1.length()/2; 
			cout << temp2 << endl;
			// If the jth letter of the string equal the middle character add to count2
			if(temp2 == temp1[j]){
				count2++;
				cout << "count2: " << count2 << endl;
			}
			// Else add to count three
			else{
				count3++;
				cout << "count3: " << count3 << endl;
			}
		}
	}
		
		/* If count2-1 (because we counted the middle letter) is odd and 
		 * count3 (the rest of the letters) is even, return true
		 */
		if((count2-1) % 2 == 1 && count3 % 2 == 0){
			return true;
		}
		
		else{
			return false;
		}
}

/* Analyze the vectors seperately, if the leftmost half of the string vector
 * is equal to the leftmost half, it passes the test.
 */  
bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	string temp1, left1, right1, temp2, left2, right2; 
	locale loc;
	
	// Convert the string vector to one long string
	for(unsigned int i = 0; i < stringVector1.size(); i++){
		temp1 = temp1 + stringVector1.at(i);
	}
	
	//Convert string to lower case
	for(unsigned int i = 0; i < temp1.size(); i++) {
		temp1[i] = tolower(temp1[i],loc);
	}
		
	// Do some substring vodoo, make even and odd cases for the now converted strings
	if(temp1.length() % 2 == 1){ 
		left1 = temp1.substr(0, (temp1.size()/2+1));
	}
	
	else{
		left1 = temp1.substr(0, temp1.size()/2);
	}
	
	right1 = temp1.substr(temp1.size()/2, temp1.size());		
	// Make right1 backwards
	reverse(right1.begin(), right1.end());
		
	// Convert the string vector to one long string		
	for(unsigned int j = 0; j < stringVector2.size(); j++){	
		temp2 = temp2 + stringVector2.at(j);
	}
	
	//Convert string to lower case
	for(unsigned int i = 0; i < temp2.size(); i++) {
		temp2[i] = tolower(temp2[i],loc);
	}
	
	// Do some substring vodoo, make even and odd cases for the now converted strings
	if(temp2.length() % 2 == 1){ 
		left2 = temp2.substr(0, (temp2.size()/2+1));
	}
	
	else{
		left2 = temp2.substr(0, temp2.size()/2);
	}
	
	right2 = temp2.substr(temp2.size()/2, temp2.size());
	// Make right2 backwards
	reverse(right2.begin(), right2.end());
	
	// If the left side and the right side of the strings are equal, we have a palindrome
	if(left1 == right1 && left2 == right2){
		return true;
	} 
	
	else{
		return false;
	}
}

bool FindPalindrome::add(const string & value)
{
		unsigned int count = 0;
		
		// Check if each character in the string is alphabetical
		for(unsigned int i = 0; i < value.length(); i++){
			
			if(isalpha(value[i])){
				count++;
			}
		}
		
		// If the string checks out add the string to the palindromeString vector
		if(count == value.length()){
			palindromeString.push_back(value);
			// Call recursive function, pass in plaindromeString and empty vector of strings
			recursiveFindPalindromes(palindromeString, Empty);
			return true;
		}
		
		else{
			return false;
		}
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	/* Iterator string vector for insert function
	vector<string>::iterator it;
	* Wasn't able to get the insert function to work, replaced with pushback
	palindromeString.insert(it, stringVector.begin(), stringVector.end());
	*/
	string test1;
	string test2;
	unsigned int county = 0;
	
	// Check if the string is an allowable candidate and add to palindromeString
	for(unsigned int i = 0; i < stringVector.size(); i++){
		// Create a temporary variable to hold one long string 
		test1 = test1 + stringVector.at(i);
		
		/*test2 = stringVector.at(i);
		// Check for duplicates, works but this will screw up test before I smush the string together
		for(unsigned int j = i + 1; j < stringVector.size(); j++){
			if(stringVector.at(j) == test2){
				cout << stringVector.at(j) << " = " << test2 << "?" << endl;
				return false;
			}
		}*/
	}
	// Check if each character in the string is alphabetical	
	for(unsigned int i = 0; i < test1.length(); i++){
		
		if(isalpha(test1[i])){
			county++;
		}
	}
		
	// If the string checks out add the string to the palindromeString vector		
	if(county == test1.length()){
		palindromeString.push_back(test1);
		// Call recursive function, pass in palindromeString and empty vector of strings
		recursiveFindPalindromes(palindromeString, Empty);
		return true;
	}
	
	else{
		return false;
	}
}

// Return the palindrome vector, a vector of string vectors
vector< vector<string> > FindPalindrome::toVector() const
{
	return palindromeVector;
}

/*//Reverse the current string vector so we can easily iterate through and keep order
 * Not what I wanted to do but still coolio. Used to be in the recursive algorithm, no longer.
	reverse(currentStringVector.begin(), currentStringVector.end());
	
	// Iterate through from the back of the vector to the front, the end is now the beginning
	for(int i = currentStringVector.size(); i >= 0; i--){
	// Create a temp variable to hold the string at the current string vector position
	string temp = currentStringVector.at(i);
	// Now, delete said string from current string vector
	currentStringVector.pop_back();
	// And, add the temp variable to candidate string vector
	candidateStringVector.push_back(temp);
	
	// If current string and candidate string pass cut test 2, do recursion
	if(cutTest2(currentStringVector, candidateStringVector) == true){
		recursiveFindPalindromes(candidateStringVector, currentStringVector);
	}
}*/		

/* This program was created to demonstrate a recursive binary search of a 
 * string.
 * @author Gregory Wagonblast
 * @version 1.0
 * @since 25May2020
 */ 
 
//Include all necessary preprocessor drives
#include <cstdlib>
#include <iostream>
//Using this because I'm lazy
using std::string;

//Function prototype, string array, two ints and a string for input. Returns an int.
int BinarySearchString(string [], int, int, string);

int main(){
	//Initialize and declare variables
	int size = 100, result;
	string arr[size], target;
	
	//Prompt the user for the size of the array
	std::cout << "Enter array size: ";
	
	//GET DAT SIZE
	std::cin >> size;
	
	//Prompt the user to enter string elements into the array
	std::cout << "Enter elements of the array: ";
	
	//Collect those string elements and hold them in the array
	for(int i = 0; i < size; i++){
		std::cin >> arr[i];
	}
	
	//Enter the string that you want to search for
	std::cout << "Enter target to be searched for: ";
	
	//Hold that string
	std::cin >> target;
	
	//Declare first and last for the function
	int first = 0, last = size - 1;
	
	//Result is the return value from the recursive function
	result = BinarySearchString(arr, first, last, target);
	
	//Display the index of the string to th user
	std::cout << "Target found at index " << result;
	
	//return zero to main
	return 0;
}

/* Create a function for BinarySearchString
 * @pre Get them values from the user and use them real good
 * @post return the index of the string to main
 * @param arr[] holds the array of strings inputted from the user
 * @param first is the first index of the array (i.e. 0)
 * @param last is the last index of the array (i.e. size-1)
 * @param target is the string that you are searching for
 * @return mid is returned and then held in result. This integer holds the 
 * index of the string that the user wants to locate
 */
int BinarySearchString(string arr[], int first, int last, string target){
	//Declare midpoint and return result variables
	int mid;

	//START RECURSIVE ALGORITHM
	if(first > last){
		return -1;
	}
	
	else{
		mid = (first + last) / 2;
		
		if(arr[mid] < target){
			return BinarySearchString(arr, mid + 1, last, target);
		}
		
		else if(arr[mid] > target){
			return BinarySearchString(arr, first, mid - 1, target);
		}
		
		else{
			return mid;
		}
	}
}


/*//Create a function for BinarySearchString
int BinarySearchString(string arr[], int first, int last, string target){
	//Declare midpoint and return result variables
	int mid, index;
	
	while(first < last){
		mid = (first+last) / 2;
		
		if(arr[mid] == target){
			first = mid;
			last = mid;
		}
		
		else if(arr[mid] < target){
			first = mid + 1;
			last = mid - 1;
		}
		
	}
	
	if(first > last){
		index = -1;
	}
	
	else if(arr[mid] != target){
		index = -1;
	}
	
	else{
		index = first;
	}
		
	return index;
		
}*/

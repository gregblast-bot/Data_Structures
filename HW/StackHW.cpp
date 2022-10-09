#include "Stack.hpp"
#include <cstring>
#include <iostream>

// Default constructor
Stack::Stack(){
	top = -1;
	bottom = 0;
	length = 0;
}

// Destructor
Stack::~Stack(){
	delete [] stackPtr;
}

// Push an int onto the stack
void Stack::push(int p){
	
	/*PART C: if(top+1 != length){
	top++;
	stackPtr[top] = p;
	}

	else{ 

		if(count % 2 == 1){
			int k;
			std::cout << "Stack is full! Enter a value to resize the array: ";
			std::cin >> k;
			
			length += (k*count);
			int* newStackPtr = new int[length];
			
			for(int i = 0; i <= top; i++){
				newStackPtr[i] = stackPtr[i];
			}
			
			delete [] stackPtr;
			
			stackPtr = newStackPtr;
			top++;
			setCount(count+=2);
			stackPtr[top] = p;
		}
	}*/
	
	/*PART B:// If the top of the stack is not equal to the length, simple push
	if(top != length){
		top++;
		stackPtr[top] = p;
	}

	// Otherwise have the user adjust the stack by a h value, (h is set)
	else{
		int h;
		std::cout << "Stack is full! Enter a value to resize the array: ";
		std::cin >> h;
		
		length += h;
		top++;
		stackPtr[top] = p;
	}*/

	// PART A: If the stack becomes full, fall into this case and resize
	if(top == (length-1)){
		std::cout << "Stack is full! Resizing..." << std::endl;
		
		// Double the size of the stack
		int* newStackPtr =  new int[length*2];
		// Copies the values of "length" bytes from stackPtr to newStackPtr
		memcpy(newStackPtr, stackPtr, length);
		// Free the stackPtr's memory
		delete [] stackPtr;
		// Put the temporary stack pointer into the original
		stackPtr = newStackPtr;
		
		// Increment top, push the parameterized value to the top of the stack and double length
		top++;
		stackPtr[top] = p;
		length = length*2;
	}
	
	// If the stack is not full, increment top and push p to the top of the stack
	else{
		top++;
		stackPtr[top] = p;
	}
}

// Pop the top of the stack out
int Stack::pop(){
	
	// Fall into this case and exit if the stack is empty
	if(top == -1){
		std::cout << "Stack empty!" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	// Hold the top of the stack in a temp variable and decrement top
	int temp = stackPtr[top];
	top--;
	
	// If the stack entries has dropped to less than half the length of the stack, fall into this case	
	if(top+1 == length/2){
		std::cout << "Stack entries dropped to less than half of size! Resizing..." << std::endl;
	
		// Halve the size of the stack
		int* newStackPtr =  new int[length/2];
		// Free the stackPtr's memory
		delete [] stackPtr;
		
		//Instead of using memcpy, we will use a for loop to perform the same function
		for(int i = 0; i <= top; i++){
			stackPtr[i] = newStackPtr[i];
		}
		
		// Put the temporary stack pointer into the original and update length to half
		stackPtr = newStackPtr;
		length = length/2;
	}
	
	// Return temp variable
	return temp;
}

// Print all relevant information
void Stack::print(){
	// Initialize pointer to pointer
	int** stackPtr2Ptr = &stackPtr;
	
	std::cout <<  std::endl << "Length of stack is " << length << std::endl;
	std::cout << "Top of stack is " << top << std::endl;
	std::cout << "Stack pointer address is " << stackPtr << std::endl;
	std::cout << "Stack pointer reference is " << &stackPtr << std::endl;
	std::cout << "Stack pointer to pointer address is " << stackPtr2Ptr << std::endl << std::endl;
	
	for(int i = 0; i <= top; i++){
		std::cout << "Stack pointer value at index " << i << " is " << *(stackPtr+i) << std::endl;
    }
}

// Member function gets length
int Stack::getLength(){
	return length;
}

// Member function sets length
void Stack::setLength(int l){
	length = l;
}

// Member function prints length
void Stack::printLength(){
	std::cout << "Length is now " << length << std::endl;
}

// Member function gets the stack pointer
int* Stack::getStackPtr(){
	return stackPtr;
}

// Member function sets the stack pointer
void Stack::setStackPtr(int* sp){
	stackPtr = sp;
}

// Member function gets count
int Stack::getCount(){
	return count;
}

// Member function sets count
void Stack::setCount(int c){
	count = c;
}

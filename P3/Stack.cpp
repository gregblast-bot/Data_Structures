//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// Default constructor, set head pointer to null pointer and size to zero
template<class ItemType>
Stack<ItemType>::Stack() 
{
	headPtr = nullptr;
	currentSize = 0;
}  // end default constructor


// Destructor utilizes pop to destroy the stack
template<class ItemType>
Stack<ItemType>::~Stack()
{
	// Pop until the stack is empty
	while(!isEmpty()){
		pop();
	}
}  // end destructor

// Check if stack is empty
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	// If head pointer is null, stack is empty. Else, stack has elements
	if(headPtr == nullptr){
		return true;
	}
	
	else{
		return false;
	}
	
	// Could just do this too, [return headPtr == nullptr;]
}  // end isEmpty

// Return current size
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// Push an item onto the stack
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	// Instantiate a new dynamic pointer, head pointer now equals new pointer
	Node<ItemType>* newPtr = new Node<ItemType>(newItem, headPtr);
	headPtr = newPtr;
	newPtr = nullptr;
	currentSize++;
	return true;
}  // end push

// Peek into the stack, peek-a-boo
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(logic_error)
{
	ItemType returnItem;
	// Enforce precondition during debugging
	if(isEmpty()){
		throw logic_error("Empty");
	} 
	
	// Our return item is the element at the head of the stack
	returnItem = headPtr -> getItem();
	return returnItem;
}  // end peek

// Pop an item off the stack
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	bool result = false;
	
	// If stack is not empty, delete the top
	if(!isEmpty()){
		Node<ItemType>* deletePtr = headPtr;
		headPtr = headPtr -> getNext();
		
		// Return deleted node
		deletePtr -> setNext(nullptr);
		delete deletePtr;
		deletePtr = nullptr;
		currentSize--;
		
		result = true;
	}
	
	return result;	
}  // end pop

// Clear the element of the stack
template<class ItemType>
void Stack<ItemType>::clear()
{
	Node<ItemType>* deletePtr = headPtr;
	
	// While head pointer is not null, continue updating and deleting from memory
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();
		deletePtr->setNext(nullptr);
		delete deletePtr;
		deletePtr = headPtr;
	} 
	
	// Set the size to zero
	currentSize = 0;
	
	// This is the simplest and crudest way to clear [headPtr == nullptr]
}  // end clear


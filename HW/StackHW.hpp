#ifndef STACK_H
#define STACK_H

class Stack{
	
private:

int* stackPtr;
int top;
int bottom;
int length;
int count = 3;

public:

Stack();
~Stack();	
void push(int p);
int pop();
void print();
void setLength(int l);
int getLength();
void printLength();
void setStackPtr(int* sp);
int* getStackPtr();
void setCount(int c);
int getCount();

		
};

#endif

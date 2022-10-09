#include "Stack.cpp"
#include <iostream>

using namespace std;

int main(){
	Stack s;
	int length;
	int* stackPtr;
	
	while(s.getLength() <= 0){
		cout << "Enter stack length: ";
		cin >> length;
		s.setLength(length);
		cout << endl;
	}
	
	stackPtr = new int[length];
	
	s.setStackPtr(stackPtr);
	
	s.push(1);
	s.printLength();
	s.push(2);
	s.printLength();
	s.push(3);
	s.printLength();
	s.push(4);
	s.printLength();
	s.push(5);
	s.printLength();
	s.push(6);
	s.pop();
	s.pop();
	s.pop();
	s.printLength();
	s.push(7);
	s.printLength();
	s.push(8);
	s.pop();
	s.printLength();
	s.push(9);
	s.printLength();
	s.push(10);
	s.printLength();
	s.push(11);
	s.printLength();
	s.push(12);
	s.printLength();
	s.push(13);
	s.printLength();
	s.push(14);
	s.printLength();
	s.push(15);
	s.printLength();
	s.push(16);
	s.printLength();
	s.push(17);
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.printLength();
	s.push(18);
	s.printLength();
	s.push(19);
	s.printLength();
	s.push(20);
	s.printLength();
	s.push(21);
	s.printLength();
	s.print();
}

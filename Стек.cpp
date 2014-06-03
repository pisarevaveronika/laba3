#include <iostream>

using namespace std;

/**
@class Stack
Class containing the elements of the stack and methods for working with the stack.
*/
class Stack {
	private:
		/// @param numberofelements – variable responsible for the length of the stack
		int numberofelements;

		/// @param value – an array containing the values ​​of the stack
		int* value;

	public:

		/**
		@function Stack
		The class constructor. Takes the stack length, creates an array of length values
		@param capacity – variable responsible for the length of future class
		*/
		Stack(int capacity) {
			value = new int [capacity];
			numberofelements=0;
		};
		
		/**
		@function Put
		Function that puts element to the stack. Takes the value to be written to the stack, shifts the value of the stack
		@param newvalue – variable which is inserted
		*/
		void PutElement(int newvalue) {
			value[numberofelements++] = newvalue;
		};

		/**
		@function Take
		Function that take the element of the stack, returning the value of the specific number.
		@return element from the list
		*/
		int TakeElement() {
			return value[--numberofelements];
		};

		int ShowElement() {
			return value[numberofelements];
		};

};

int main (void){
	int n=0;
	cout<<"Put the number of elements for your STACK: ";
	cin>>n;
	cout<<endl;
	Stack S(n);
	for (int i=0; i<n; i++){
		int j=0;
		cout<<"Element "<<i+1<<": ";
		cin>>j;
		S.PutElement(j);	
	};
	cout<<"Your STACK is full now"<<endl<<endl<<"Printing it out:"<<endl<<endl;
	for (int i=(n-1); i>(-1);i--){
		int j=S.TakeElement();
		cout<<"Element "<<i+1<<": "<<j<<endl;
	};
	return 0;
}
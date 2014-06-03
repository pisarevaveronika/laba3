#include <iostream>

/**@mainpage
<pre>
<b>Lists</b>
	<i>Stacks</i>
		<a href = "http://adorning.ru/2010/01/21/urok-11-c-stl-steki-i-ocheredi-stack-and-queue/">Queues</a>
</pre>
*/

using namespace std;

/**
@class Queue
Class containing the elements of the queue and methods for working with the queue.
*/
class Queue{
private:
	/// @param length – variable responsible for the length of the queue
	int length;
	/// @param head – variable indicating the head
	int head;
	/// @param tail – variable indicating the tail of the queue
	int tail;
	/// @param data – an array containing the values ​​of the queue
	int* data;

public:
	/**
	@function Queue
	The class constructor. Takes the queue length, creates an array of length values ​​and puts the head and tail to zero
	@param size – variable responsible for the length of future class
	*/
	Queue(int size){
		data = new int[size];
		head = 0;
		tail = head;
		length = size;
	}

	/**
	@function Put
	Function that puts element to the queue. Takes the value to be written to the queue, shifts the value of the tail, writing the specified value to a specific cell
	@param value – variable which is inserted
	*/
	void Put(int value) {
		 if (++tail == length){
			 tail = 0;
		 }
		 data[tail] = value;
	 }

	/**
	@function Take
	Function that take the element of the queue. Shifts the value of the head, returning the value of the end of the queue.
	@return element from the end of the queue
	*/
	int Take() {
		
		if (++head == length)
			head = 0; 
		return data[head];
		
	}
};



int main(void){
	int n = 0;
	cout << "Put the number of elements for your QUEUE: ";
	cin >> n;
	cout << endl;
	Queue OP(n);
	for (int i = 0; i<n; i++){
		int j = 0;
		cout << "Element " << i + 1 << ": ";
		cin >> j;
		OP.Put(j);
	};
	cout << "Your QUEUE is full now" << endl << endl << "Printing it out:" << endl << endl;
	for (int i = (n - 1); i>(-1); i--){
		int j = OP.Take();
		cout << "Element " << i + 1 << ": " << j << endl;
	};
	return 0;
}
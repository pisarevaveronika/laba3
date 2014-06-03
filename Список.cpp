#include <iostream>

using namespace std;

/**
@struct List
Struct containing the element of the list and ponter to the next struct.
*/
typedef struct List {
    int number;
    List *next;
} List;

/// @param head – pointer to the head of the list
List *head = NULL;

/**
@function Put
Function that puts element to the list. Takes the value to be written to the queue, shifts the value of the list and also takes the pointeer to the head of the list
@param data – variable which is inserted
@param tmp - list for temporary copy
*/
void Put(List **head, int data) {
    List *tmp = new List;
    tmp->number = data;
    tmp->next = (*head);
    (*head) = tmp;
};

/**
@function Take
Function that take the element of the list. Shifts the pointers of the elements, returning the value of the specific number.
@param last – list for temporary copy
@return element from the list
*/
int Take(List **head) {
	List* last = NULL;
	if (head == NULL) {
		return 0;
	}
	last = (*head);
	int val = last->number;
	(*head) = (*head)->next;
	free(last);
	return val;
};

/**
@function Get
Function that take the element of the list. Shifts the pointers of the elements, returning the value of the specific number.
@param counter – counts the elements
@return element from the list
*/
List* Get(List* head, int n) {
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter++;
	}
	return head;
}


/**
@function Put
Function that puts element to the list. Takes the value to be written to the queue, shifts the value of the list and also takes the pointeer to the head of the list
@param val – variable which is inserted
@param n - number of the element
*/
void Insert(List *head, int n, int val) {
	List *tmp = NULL;
	int i = 0;
	while (i < n && head->next) {
		head = head->next;
		i++;
	}
	tmp = new List;
	tmp->number = val;
	if (head->next) {
		tmp->next = head->next;
	}
	else {
		tmp->next = NULL;
	}
	head->next = tmp;
}

/**
@function PrintList
Prints the list
@param com – variable of the size of the list
*/
void PrintList(List *head, int com) {
	int i = com;
	while (head) {
		cout << "Element "<< i <<": "<< head->number<<endl;
		head = head->next;
		i--;
	}
}


/**
@function Delete
Delete the list
@param n - number of the element
*/
int Delete(List **head, int n) {
	if (n == 0) {
		return Take(head);
	}
	else {
		List *prev = Get(*head, n - 1);
		List *elm = prev->next;
		int val = elm->number;
		prev->next = elm->next;
		free(elm);
		return val;
	}
}

int main (void){
	int n=0;
	int p = 0;
	int q = 0;
	cout<<"Put the number of elements for your LIST: ";
	cin>>n;
	cout<<endl;
	List *head=NULL;
	for (int i=0; i<n; i++){
		int j=0;
		cout<<"Element "<<i+1<<": ";
		cin>>j;
		Put(&head, j);
	};
	cout << "On what place you want to add the number? Place: ";
	cin >> p;
	cout << "What number you want to add? ";
	cin >> q;
	Insert(head, p, q);
	cout << "What place you want to delete? Place: ";
	cin >> p;
	Delete(&head, p);
	cout << "Your LIST is ready now" << endl << endl << "Printing it out:" << endl << endl;
	PrintList(head, n);
	return 0;
}
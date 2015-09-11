/* Problem 5:  */
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
	int value;
	Node *next;
};

/* Purpose: splits list "in" to smaller list for elements <= pivot and larger list for elements > pivot
param: pointers to list "in", "smaller", "larger", and int pivot
return: none
*/
void split (Node*& in, Node*& smaller, Node*& larger, int pivot) {
	Node* curr = in;
	if (curr == NULL) {
		smaller->next = NULL;
		larger->next = NULL;
	} else {
		Node* newNode = new Node; // create new node
		if (curr->value <= pivot) {
			smaller->value = curr->value; // add new node to smaller list
			smaller->next = newNode;

			// delete current Node
			Node* next = curr->next;
			delete curr;
			split (next, smaller->next, larger, pivot);
		} else { 
			larger->value = curr->value;
			larger->next = newNode;

			// delete current Node
			Node* next = curr->next;
			delete curr;
			split (next, smaller, larger->next, pivot);
		}
	}
	
}

int main(int argc, char* argv[]) {
	Node* myNode = new Node;
	Node* head = myNode;

	srand(time(0));
	for (int i=0; i<6; i++) {
		myNode->value = rand() % 20;
		Node* newNode = new Node;
		myNode->next = newNode;
		myNode = myNode->next;
	}

	myNode = NULL;
	for (Node *p = head; p->next != NULL; p=p->next) {
		cout << p->value << endl;	
	}

	Node* smaller = NULL; //new Node;
	Node* larger = NULL;//new Node;
	int pivot = 10;
	split (head, smaller, larger, pivot);

// TESTING
	cout << "\nsmaller list: " << endl;
	while (smaller->next) {
		cout << smaller->value << " ";
		smaller = smaller->next;
	} 

	cout << "\nlarger list: " << endl;
	while (larger->next) {
		cout << larger->value << " ";
		larger = larger->next;
	} 

	return 0;
}
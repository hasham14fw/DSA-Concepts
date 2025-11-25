#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = nullptr;
	}
};

class Linklist {
public:
	Node* head = nullptr;
	int size = 0;


	void add_front(int n) {
		Node* newNode = new Node(n);
		size++;
		Node* temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		newNode->next = head;
		head = newNode;
		temp->next = head;
	}


	void add_last(int n) {
		add(n);
	}


	void pop_last() {

		if (head == nullptr) {
			cout << "Empty List";
		}

		else if (head->next == nullptr) { // if only one node
			delete head;
			head = nullptr;
		}

		else {
			Node* temp = head;
			while (temp->next->next != head) {
				temp = temp->next;
			}

			delete temp->next;
			temp->next = head;
		}
		size--;
	}

	void pop_first() {

		Node* temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}

		Node* temp1 = head;
		head = head->next;
		delete temp1;
		temp->next = head;
		size--;

	}


	void add(int n) {
		Node* newNode = new Node(n);
		size++;

		if (head == nullptr) {
			head = newNode;
			newNode->next = head;
		}

		else {
			Node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = head;
		}
	}

	void first_node() {
		cout << "\nValue First Node: " << head->data;
	}

	void last_node() {
		Node* temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		cout << "\nLast Node: " << temp->data;
	}

	void search(int n) {
		int i = 0;
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->data == n) {
				cout << "\nValue found at Index: " << i;
				break;
			}
			temp = temp->next;
			i++;
		}
	}

	void display() {
		Node* temp = head;
		do {
			cout << temp->data << "->";
			temp = temp->next;
		} while (temp != head);
	}
};
int main() {
	Linklist n1;
	n1.add(10);
	n1.add(20);
	n1.add(30);
	n1.add_front(99);
	n1.add_last(100);
	n1.pop_last();
	n1.pop_first();
	n1.display();
	n1.first_node();
	n1.last_node();
	n1.search(30);
	return 0;
}
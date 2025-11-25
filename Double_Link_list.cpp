#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node* next;
	Node* prev;
public:
	Node(int val) {
		data = val;
		next = nullptr;
		prev = nullptr;
	}
	friend class Linklist;
};

class Linklist {
public:
	Node* head = nullptr;
	int size = 0;


	void add_front(int n) {
		Node* newNode = new Node(n);
		size++;
		newNode->next = head;
		head = newNode;
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
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
		}
		size--;
	}

	void pop_first() {
		if (head == nullptr) {
			cout << "\nEmpty";
		}

		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
		temp = nullptr;
		head->prev = nullptr;
	}

	void add(int n) {
		Node* newNode = new Node(n);
		size++;

		if (head == nullptr) {
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->prev = temp;
	}

	void first_node() {
		cout << "Value First Node: " << head->data;
	}

	void last_node() {
		if (head == nullptr) {
			cout << "List is Empty";
		}

		else {
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			cout << "\nLast Node: " << temp->data;
		}
	}


	void search(int n) {
		if (head == nullptr) {
			cout << "List is Empty";
		}
		else {
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

	}

	void display() {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << "->";
			temp = temp->next;
		}
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
	n1.search(10);
	return 0;
}
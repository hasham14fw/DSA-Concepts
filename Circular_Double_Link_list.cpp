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
		Node* last = head->prev;
		newNode->next = head;
		head = newNode;
		newNode->prev = last;
		last->next = head;

	}


	void add_last(int n) {
		add(n);
	}


	void pop_last() {
		if (head == nullptr) {
			cout << "\nEmpty List";
			return;
		}

		else if (head->next == head) {
			delete head;
			head = nullptr;
		}

		else {
			Node* last = head->prev;
			Node* secondLast = last->prev;

			secondLast->next = head;
			head->prev = secondLast;

			delete last;
		}
	}



	void pop_first() {
		if (head == nullptr) {
			cout << "\nEmpty";
		}
		Node* last = head->prev;
		Node* temp = head;
		head = head->next;
		head->prev = last;
		delete temp;
		size--;
		temp = nullptr;
		last->next = head;
	}

	void add(int n) {
		Node* newNode = new Node(n);
		size++;


		if (head == nullptr) {
			head = newNode;
			newNode->next = head;
			newNode->prev = head;
		}

		else {
			Node* last = head->prev;
			last->next = newNode;
			newNode->next = head;
			newNode->prev = last;
			head->prev = newNode;
		}
	}

	void first_node() {
		cout << "Value First Node: " << head->data;
	}

	void last_node() {
		Node* last = head->prev;
		cout << "\nValue at last Node: " << last->data;
	}


	void search(int n) {
		if (head == nullptr) {
			cout << "List is Empty";
		}
		else {
			int i = 0;
			Node* temp = head;
			do {
				if (temp->data == n) {
					cout << "\nValue found at Index: " << i;
					break;
				}
				temp = temp->next;
				i++;
			} while (temp != head);
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
	n1.add(40);
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
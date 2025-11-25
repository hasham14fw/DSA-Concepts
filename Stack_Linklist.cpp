#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class Stack {
public:
    Node* top = nullptr;
    int size = 0;

    bool isEmpty() {
        return top == nullptr;
    }

    void pull(int v) {
        Node* newNode = new Node(v);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void peak() {
        cout << "\nTop Most: " << top->data;
    }
    int getSize() {
        return size;
    }
    void pop() {
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        temp = nullptr;
    }
    void display() {
        if (isEmpty()) {
            cout << "\nEmpty List" << endl;
        }
        else {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << "->";
                temp = temp->next;
            }
        }
    }
};

int main() {
    Stack s;
    s.pull(10);
    s.pull(20);
    s.pull(30);
    s.pop();
    s.display();
    s.peak();

    return 0;
}
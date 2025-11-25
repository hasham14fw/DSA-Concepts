#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int* arr;
public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void pop() {
        if (isEmpty()) {
            cout << "\nStack is Empty!" << endl;
        }
        else {
            arr[top--];
        }
    }

    void peak() {
        if (isEmpty()) {
            cout << "\nStack is Empty!" << endl;
        }
        else {
            cout << "\nTop most: " << arr[top];
        }
    }

    void pull(int v) {
        if (isFull()) {
            cout << "\nFull Stack";
        }
        else {
            arr[++top] = v;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "\nStack is Empty!" << endl;
            return;
        }
        cout << "\nStack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack s1(5);
    s1.pull(1);
    s1.pull(2);
    s1.pull(3);
    s1.pull(4);
    s1.pop();
    s1.peak();
    s1.display();

}
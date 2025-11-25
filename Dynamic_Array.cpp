#include <iostream>
using namespace std;


void add_front(int* arr, int n, int& s) {
	for (int i = s;i > 0;i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = n;
	s++;
}


void add_last(int* arr, int n, int& s) {
	arr[s] = n;
	s++;
}


void pop_front(int* arr, int& s) {
	for (int i = 0; i < s - 1; i++) {
		arr[i] = arr[i + 1];
	}
	s--;
}


void pop_last(int* arr, int& s) {

	s--;
}

void frequency(int* arr, int n, int& s) {
	int count = 0;
	for (int i = 0;i < s;i++) {
		if (arr[i] == n) {
			count++;
		}
	}
	cout << "Frequency of Given Value: " << count;
}

void search_val(int* arr, int a, int& s) {
	for (int i = 0;i < s;i++) {
		if (arr[i] == a) {
			cout << "Index of Given Value: " << i << endl;
			break;
		}
	}
}
void search_ind(int* arr, int n, int& s) {
	for (int i = 0;i < s;i++) {
		if (i == n) {
			cout << "Value at Given Index: " << arr[i] << endl;
			break;
		}
	}
}
void display(int* arr, int& s) {
	for (int i = 0;i < s;i++) {
		cout << arr[i] << " " << endl;
	}
	cout << "Size:" << s;
}

int main() {
	int size = 5;
	int* arr = new int[size] {10, 20, 30, 40, 50};

	add_front(arr, 99, size);
	/*add_last(arr, 99, size);*/
	/*search_ind(arr, 3, size);*/
	/*search_val(arr, 50, size);*/
	//display(arr, size);
	//pop_front(arr, size);
	/*pop_last(arr, size);*/
	display(arr, size);
	/*frequency(arr, 20, size);*/
	return 0;
}
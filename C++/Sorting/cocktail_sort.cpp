#include <iostream>
using namespace std;


void cocktailSort(int a[], int n) { // array and number of elemmets inside.
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
		swapped = false; // reset since it may be true from previous iteration

		// First loop- left to right
		for (int i = start; i < end; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]); // built in function in std namespace
				swapped = true;
			}
		}
		if (!swapped) { // if nothing moves store array
			break;
		} else{
			swapped = false; // reset flag
		}

		// Second loop- right to left
		for (int i = end - 1; i >= start; --i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		// increase the starting point so it stays in bounds
		++start;
	}
}

void printArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
}



int main() {
	int arr[] = { 7, 2, 3, 2, 9, 0, 0, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	cocktailSort(arr, n); // array and numb or elements
	cout << "Sorted array: " << endl;
	printArr(arr, n);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;


/*
	Worst case time complexity: O(n2)
	Average case time complexity: O(n)

	If random pivot is used in lomutoPartition, 
	even in worst case, time complexity is O(n)
*/


int lomutoPartition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	
	for (int j = low; j <= high - 1; ++j) {
		if (arr[j] < pivot) {
			++i;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}


int kthSmallest(int arr[], int arrSize, int k) {
	int low = 0;
	int high = arrSize - 1;
	
	while (low <= high) {
		int partitionIndex = lomutoPartition(arr, low, high);
		
		if (partitionIndex == k - 1) {
			return partitionIndex;
		} else if (partitionIndex > k - 1) {
			high = partitionIndex - 1;
		} else {
			low = partitionIndex + 1;
		}
	}
	
	return -1;
}


int main() {
	int arrSize;
	cout << "Enter size of array: ";
	cin >> arrSize;
	
	int arr[arrSize];
	cout << "Enter elements of array: ";
	for (int i = 0; i < arrSize; ++i) {
		cin >> arr[i];
	}
	
	int k;
	cout << "Which smallest th number do you want to find? ";
	cin >> k;
	
	cout << k 
		<< "th smallest number is: " 
		<< arr[kthSmallest(arr, arrSize, k)] 
		<< "\n";
	
	return 0;
}

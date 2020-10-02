#include<iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    int i, j, min;
    for(i = 0 ; i < size -1 ; i++) {
        min = i;
        for(j = i + 1 ; j < size ; j++)
            if(arr[j] < arr[min])
                min = j;
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for(int i = 0 ; i < n ; i++) 
        cin >> arr[i];
        
    cout << "Array before Sorting: ";
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    selectionSort(arr, n);
    cout << "Array after Sorting: ";
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

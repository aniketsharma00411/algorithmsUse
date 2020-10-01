#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int end = n-1;
    int start = 0;

    while(start <= end){
        int mid = (start + end)/2;

        if(arr[mid]<key){
            start = mid+1;
        }
        else if(arr[mid]>key) {
            end = mid - 1;
        }
        else {
            cout<<"Element found "<<endl;
            break;
        }

    }

}

int main() {

    return 0;
}

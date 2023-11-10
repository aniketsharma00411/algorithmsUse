#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,1,10,22,2002,12,2001};
    int n = sizeof(arr)/sizeof(arr[0]);

    int min = INT_MIN;
    for(int i=0;i<n;i++){
        if(min < arr[i]){
            min=arr[i];
            cout<<min;
        }else{
            cout<<min;
        }
        cout<<" ";
    }
    
    return 0;
}

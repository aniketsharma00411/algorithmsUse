#include <bits/stdc++.h>
using namespace std;



int min(int x, int y) { return (x<=y)? x : y; }


int fibMonaccianSearch(int arr[], int x, int n)
{

    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;


    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }

    int offset = -1;


    while (fibM > 1)
    {

        int i = min(offset+fibMMm2, n-1);


        if (arr[i] < x)
        {
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }


        else if (arr[i] > x)
        {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        else return i;
    }


    if(fibMMm1 && arr[offset+1]==x)return offset+1;


    return -1;
}


int main(void)
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x = 0;
    cout<<"Enter the element you want to search in the array using Fibonacci search: ";
    cin>>x;
    int ind=fibMonaccianSearch(arr, x, n);
    cout<<"Found at index: "<<ind<<endl;
    return 0;
}


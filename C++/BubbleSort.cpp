#include<iostream>

using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[],int n)
{
    for(int i =0;i<n-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapped= true;
            }  
        }
        if(!swapped)
        break;
    }
}

void printArray(int arr[],int x)
{
    for(int i=0;i<x;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int my_arr[n];

    cout<<"Start entering "<<n<<" numbers now..";

    for(int i=0;i<n;i++)
        cin>>my_arr[i];
    
    cout<<"Array before sorting is: ";
    printArray(my_arr,n);
    BubbleSort(my_arr,n);
    cout<<"Array after sorting is: ";
    printArray(my_arr,n);
    
}
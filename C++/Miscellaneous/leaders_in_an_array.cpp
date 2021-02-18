//Given an array A of positive integers.
//Your task is to find the leaders in the array.
//PS: An element of array is leader if it is greater than or equal to all the elements to its right side.
//Also, the rightmost element is always a leader.
// Time Complexity: O(N).
// Auxiliary Space: O(N).

#include <iostream>
#include <cmath>
using namespace std;

void leader(int arr[], int n)
{
	int curr_ldr = arr[n - 1];
	cout<<curr_ldr<<" ";
	for(int i = n - 2; i >= 0; i--)
	{
		if(curr_ldr < arr[i])
		{
			curr_ldr = arr[i];
			cout<<curr_ldr<<" ";
		}
	}
}

int main()
{
      int arr[] = {7, 10, 4, 10, 6, 5, 2}, n = 7;
      leader(arr, n);
}

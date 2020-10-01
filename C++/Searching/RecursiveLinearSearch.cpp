// Recursive C++ program
// to search x in array
#include<bits/stdc++.h>

using namespace std;

// Recursive function to
// search x in arr[l..r]
int recSearch(int arr[], int l,
			int r, int x)
{
	if (r < l)
		return -1;
	if (arr[l] == x)
		return l;
	if (arr[r] == x)
		return r;
	return recSearch(arr, l + 1,
						r - 1, x);
}

// Driver Code
int main()
{
    cout<<"Enter size of array \n";
        int n;
        cin>>n;
        int arr[n];
        cout<<"Enter array elements";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
int x;
cout<<"Enter the Element you want to search\n";
cin>>x;

	int index = recSearch(arr, 0, n - 1, x);
	if (index != -1)
	cout << "Element " << x
		<< " is present at index "
		<< index;
	else
		cout << "Element" << x
			<< " is not present" ;
	return 0;
}

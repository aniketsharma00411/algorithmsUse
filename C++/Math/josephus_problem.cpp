//Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.
//The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive. 
//Time Complexity: O(N).
//Auxiliary Space: O(N).

#include <bits/stdc++.h>
using namespace std;
int josephus(int n, int k);
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}

int josephus(int n, int k)
{
    if(n==0)
        return 0;
    else
        return(josephus(n-1,k)+k-1)%n +1;
}

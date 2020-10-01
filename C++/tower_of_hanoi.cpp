#include<iostream>
using namespace std;
void tower(char a,char b,char c,int n)
{
	if(n==1)
	{
		printf("%d disk from %c to %c\n",n,a,c);
		return;
	}
	tower(a,c,b,n-1);
	printf("%d disk from %c to %c\n",n,a,c);
	tower(b,a,c,n-1);
}

int main()
{
	int n;
	printf("Enter number of disks:");
	cin>>n;
	tower('a','b','c',n);
	return 0;
}

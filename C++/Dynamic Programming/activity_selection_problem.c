#include<stdio.h>
#define MAX 20

int n;

struct activity
{
	int index;
	int s;
	int f;
}A[MAX],temp;

void activity_selector()
{
	int i=0,j;
	printf("A%d ",A[i].index);
	for(j=1;j<n;j++)
	{
		if(A[j].s >= A[i].f)
		{
			printf("A%d ",A[j].index+1);
			i = j;
		}
	}
}

void input_activity()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter index of activity/activity no. :");
		scanf("%d",&A[i].index);
		printf("Enter start time:");
		scanf("%d",&A[i].s);
		printf("Enter finish time:");
		scanf("%d",&A[i].f);
	}
}

void sort_activity()
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(A[j].f < A[min].f)
			{
				min = j;
			}
		}
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}



void main()
{
	int i;
	
	printf("Enter number of activities:");
	scanf("%d",&n);
	input_activity();
	
	sort_activity();
	
	printf("\nMaximum size mutually compatible activities are:\n\n");
	activity_selector();	
}

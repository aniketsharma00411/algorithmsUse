#include<stdio.h>
#define MAX 10

int n,W;
double x[MAX];

struct knapsack
{
	int v;
	int w;
}K[MAX],temp;

void fractional_knapsack()
{
	int weight = 0;
	int i=0;
	while(weight + K[i].w <= W)
	{
		x[i] = 1;
		weight = weight + K[i].w;
		i++;
	}
	x[i] = (double)(W-weight)/K[i].w;

}

double calc()
{
	double val = 0;
	int i;
	for(i=0;i<n;i++)
	{
		val = val + (double)(K[i].v * x[i]);
	}
	
	return val;
}

void input_data()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter value of  item %d:",i);
		scanf("%d",&K[i].v);
		printf("Enter its weight:");
		scanf("%d",&K[i].w);
	}
}

void sort_data()
{
	int i,j,max;
	for(i=0;i<n-1;i++)
	{
		max = i;
		for(j=i+1;j<n;j++)
		{
			double r1 = (double)K[j].v / K[j].w; 
    		double r2 = (double)K[max].v / K[max].w; 
    		
			if(r1 > r2)
			{
				max = j;
			}
		}
		temp = K[i];
		K[i] = K[max];
		K[max] = temp;
	}
}



void main()
{
	int i;
	printf("Enter number of items:");
	scanf("%d",&n);
	input_data();
	printf("Enter the knapsack capacity:");
	scanf("%d",&W);
	for(i=0;i<n;i++)
		x[i] = 0;

	sort_data();
	fractional_knapsack();
	
	for(i=0;i<n;i++)
		printf("%lf ",x[i]);
	
	double val = calc();
	printf("\nTotal value of selected item is %lf.",val);			
}

/*
Shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process
with the smallest execution time to execute next. SJN is a non-preemptive algorithm.
*/

#include<stdio.h>
#define N 15 // default size for 15 to init the array to zeros
int main(){
    int i,j,k,t,t1,bt[N]={0},at[N]={0},tat[N]={0},wt[N]={0},ct[N]={0};
	int n,tBT=0,time=0, swap;
	float sumtat=0,sumwt=0;

    printf("Enter total process: ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("\nEnter Arrival Time for process %d: ",i+1);
		scanf("%d",&at[i]);
	}
	for(int i =0;i<n;i++){
	    printf("\nBurst Time for process %d: ",i+1);
	    scanf("%d",&bt[i]);
	}

	//Sorting based on arrival time
	for(i=0;i<n;i++){
        for(j=i+1; j<n; j++){
            if(at[i] > at[j]){
                t = at[i];
                t1 = bt[i];
                at[i] = at[j];
                bt[i] = bt[j];
                at[j] = t;
               bt[j] = t1;
            }
        }
    }

    k=1;
    //checking burst time and sorting
    for(j=0;j<n;j++){
        time = time + bt[j];
        t = bt[k];
        for(i=k;i<n;i++){
            if(time>=at[i] && bt[i]<t){
                swap = at[k];
                at[k] = at[i];
                at[i] = swap;
                swap = bt[k];
                bt[k] = bt[i];
                bt[i] = swap;
            }
        }
        k++;
    }

    tBT = at[0];
    for( j=0;j<n;j++){
		tBT+=bt[j];
		ct[j]+=tBT;
	}

	for(k=0;k<n;k++){
		tat[k]=ct[k]-at[k];
		wt[k]=tat[k]-bt[k];
		sumtat+=tat[k];
        sumwt+=wt[k];
	}

	printf("\n\n\t\t\t\t\tSJF\n\n\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\t\n\n");

	for(i=0;i<n;i++){
		printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("----------------------------------------------------------------------------------------------------------------");
	printf("\nTotal\t\t\t\t\t\t\t\t\t\t%.2f\t\t\t\t%.2f\n",sumtat,sumwt);

	printf("\n\nAverage Turnaround Time = %f\n",sumtat/n);
	printf("Average WT = %f\n\n",sumwt/n);
  //return 0 for some compliers
}

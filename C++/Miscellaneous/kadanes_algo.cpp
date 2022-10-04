// kadane's Algorithm is used to find maximum subarray
// contributed by devanshi katyal
// Time complexity:O(n) as array is iterated only once
// Space complexity: O(1) since no extra space is being used

#include <iostream>
using namespace std;
int kadanesAlgo(int *a, int n){
    int global_sum=a[0], currsum=a[0];
    for(int i=1;i<n;i++){
            // current sum is maximum of the ith element or previous current sum + ith element
        currsum= max(a[i], currsum+a[i]);
    // if current sum is more than the global sum, then global sum will be given value of current sum
        if(currsum>global_sum){
            global_sum= currsum;
        }
    }
    return global_sum;
}
int main() {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    int ans= kadane(a,n);
	    cout<<ans;
	    
	return 0;
}

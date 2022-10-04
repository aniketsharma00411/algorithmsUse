package Array;

import java.util.Arrays;

public class TwoPointerAlgo {

    public static void main(String[] args) {
        int arr[] = {0,-1,3,-4,5,-3,4,1};

        int n = arr.length;
        int x=0,k=0,j=n-1;

        Arrays.sort(arr);

        for(int i=0;i<n-2;i++) {
            k=i+1;
            x=-arr[i];
            j=n-1;

            while(k<j) {
                if(arr[k] + arr[j]<x) {
                    k++;
                }else if(arr[k] +arr[j] > x) {
                    j--;
                }else {
                    System.out.println(arr[i] + " "+ arr[k]+" "+arr[j]);
                    k++;
                    j--;
                }
            }
        }
    }

}

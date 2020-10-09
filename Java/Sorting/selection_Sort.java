
import java.util.Scanner;

public class selectSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        int [] arr = new int[len];

        for(int i=0;i<len;i++){
            arr[i] = sc.nextInt();
        }

        for(int i=0;i<arr.length-1;i++){
            //consider the i as the min value and compare it array
            int mini_ind = i;
            for(int j=i+1;j<arr.length;j++){
                //if arr has min-Val then set min = min-Val and continue
                if(arr[j]<arr[mini_ind]){
                    mini_ind = j;
                }
            }
            // after each iteration swap i val with min because the we want arr to be sorted in ascending order
            int temp =arr[i];
            arr[i] = arr[mini_ind];
            arr[mini_ind] = temp;
        }

        for(int a: arr){
            System.out.print(a+", ");
        }
    }
}

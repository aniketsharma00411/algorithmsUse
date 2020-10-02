//Title:Insertion sort
// Author:ShivamVerma
// Email:shivamthegreat.sv@gmail.com


void insertionSort(List arr, int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

/* Driver code */
int main()  
{  
    List arr = [ 12, 11, 13, 5, 6 ];  
    int n = arr.length;  
  
    insertionSort(arr, n);  

    for (int i = 0; i < n; i++)  
        print("${arr[i]} ");
  
    return 0;  
}  

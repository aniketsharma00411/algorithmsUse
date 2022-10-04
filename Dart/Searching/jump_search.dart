//Name: Shivam Verma


import 'dart:math';
int jumpSearch(List arr, int x, int n) 
{ 
    // Finding block size to be jumped 
    double step = sqrt(n); 
  
    // Finding the block where element is 
    // present (if it is present) 
    double prev = 0; 
    while (arr[min(step, n)-1] < x) 
    { 
        prev = step; 
        step += sqrt(n); 
        if (prev >= n) 
            return -1; 
    } 
  
    // Doing a linear search for x in block 
    // beginning with prev. 
    while (arr[prev.toInt()] < x) 
    { 
        prev++; 
  
        // If we reached next block or end of 
        // array, element is not present. 
        if (prev == min(step, n)) 
            return -1; 
    } 
    // If element is found 
    if (arr[prev.toInt()] == x) 
        return prev.toInt(); 
  
    return -1; 
} 
  
// Driver program to test function 
int main() 
{ 
    List arr = [0, 1, 1, 2, 3, 5, 8, 13, 21, 
                34, 55, 89, 144, 233, 377, 610 ]; 
    int x = 55; 
    int n = arr.length; 
      
    // Find the index of 'x' using Jump Search 
    int index = jumpSearch(arr, x, n); 
  
    // Print the index where 'x' is located 
    print("\nNumber  $x  is at index  $index"); 
    return 0; 
} 

# Binary Search based Python3  
# program to find number of  
# rotations in a sorted and 
# rotated array. 
  
# Returns count of rotations for 
# an array which is first sorted  
# in ascending order, then rotated 
def countRotations(arr,low, high): 
  
    # This condition is needed to  
    # handle the case when array 
    # is not rotated at all 
    if (high < low): 
        return 0
  
    # If there is only one  
    # element left 
    if (high == low): 
        return low 
  
    # Find mid 
    # (low + high)/2  
    mid = low + (high - low)/2;  
    mid = int(mid) 
  
    # Check if element (mid+1) is 
    # minimum element. Consider  
    # the cases like {3, 4, 5, 1, 2} 
    if (mid < high and arr[mid+1] < arr[mid]): 
        return (mid+1) 
  
    # Check if mid itself is  
    # minimum element 
    if (mid > low and arr[mid] < arr[mid - 1]): 
        return mid 
  
    # Decide whether we need to go 
    # to left half or right half 
    if (arr[high] > arr[mid]): 
        return countRotations(arr, low, mid-1); 
  
    return countRotations(arr, mid+1, high) 
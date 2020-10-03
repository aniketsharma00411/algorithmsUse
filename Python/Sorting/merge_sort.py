#!/usr/bin/python3 
'''
    Author : Karthikeyan_01
    Algo : Merge Sort 
    Time Comp : O(n logn)
'''


def merge(a , L , mid , R):
    n1 = mid - L + 1
    n2 = R - mid
    
    k = L

    Left = [0] * (n1)
    Right= [0] * (n2) 

    for i in range(0 , n1):
        Left[i] = a[i+L]

    for j in range(0 , n2):
        Right[j] = a[j + mid + 1]

    i = 0
    j = 0
    while i < n1 and j < n2:
        if Left[i] <= Right[j]:
            a[k] = Left[i]
            k += 1
            i += 1
        else:
            a[k] = Right[j]
            k += 1
            j += 1

    while i < n1:
        a[k] = Left[i]
        i += 1
        k += 1
    while j < n2:
        a[k] = Right[j]
        j += 1
        k += 1



def mergesort(a , L , R):
    if L < R:
        mid = (L + R)//2
        mergesort(a , L , mid)
        mergesort(a , mid + 1 , R)
        merge(a , L , mid , R)


if __name__ == '__main__':
    a = [ 2 , 7 , 3 , 5 , 4 , 1]
    n = len(a) 
    print("Array Before Sorting")
    for i in a:
        print(i , end = ' ')


    mergesort(a , 0 , n - 1)

    print('\n')
    print("Array After Sorting")
    for i in a:
        print(i , end=' ')




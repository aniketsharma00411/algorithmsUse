#!/usr/bin/env python
# coding: utf-8

# In[5]:


n=int(input("Enter length of array"))
arr = [] 
for i in range(1,n+1):
    element=int(input())
    arr.append(element)

for i in range(1, len(arr)): 
    key = arr[i] 
    j = i-1
    while j >=0 and key < arr[j] : 
        arr[j+1] = arr[j] 
        j -= 1
    arr[j+1] = key
print ("Sorted array is:") 
for i in range(len(arr)): 
    print ("%d" %arr[i]) 


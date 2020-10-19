class arrayData():
    # Python3 program to 
    # Function to left rotate arr[] of size n by d*/ 
    def leftRotate(self, arr, d, n): 
        for i in range(d): 
            self.leftRotatebyOne(arr, n) 
    
    # Function to left Rotate arr[] of size n by 1*/  
    def leftRotatebyOne(self, arr, n): 
        temp = arr[0] 
        for i in range(n-1): 
            arr[i] = arr[i + 1] 
        arr[n-1] = temp 
            
    
    # utility function to print an array */ 
    def printArray(self, arr, size): 
        for i in range(size): 
            print ("% d"% arr[i], end =" ")
arrayObj = arrayData()
arr = [1, 2, 3, 4, 5, 6, 7] 
arrayObj.leftRotate(arr, 3, 7) 
arrayObj.printArray(arr, 7) 

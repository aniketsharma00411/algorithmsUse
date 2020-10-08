def kadane(A):
    max_curr= A[0]
    max_global = A[0]
    for i in range(1,len(A)):
        max_curr = max(A[i],max_curr+A[i])
        if(max_curr>max_global):
            max_global = max_curr
    return max_global

A = list(map(int,input().split()))
print(kadane(A))
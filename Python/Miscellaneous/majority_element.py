"""
    input: list of elements (comparable by ==)
    output: the majority element of the list (if exists)
    A majority element is a member which occurs at least n/2 times in the list of length n
"""

def isMajorityElement(l, e):
    cnt = l.count(e)
    return cnt > len(l) // 2

def vote(l):
    best = 0
    cnt = 1
    for i in range(1, len(l)):
        if l[i] == l[best]:
            cnt += 1
        else:
            cnt -= 1
        if cnt == 0:
            best = i
            cnt = 1
    return l[best]

l = [2,3,1,4,5,6,3,2,5,6,4,6,3,2,3,4,4,3,2,1,2,2,3]
l = [2,3,2,2,5,6,2,2,5,6,2,6,3,2,2,4,2,3,2,1,2,2,3]
best = vote(l)
if isMajorityElement(l, best):
    print("Majority element is", best)
else:
    print("There is no majority element")

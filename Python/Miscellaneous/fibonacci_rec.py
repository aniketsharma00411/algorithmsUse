#!/usr/bin/python3
from sys import argv #going to be using this for light argparsing
'''
The fibonacci sequence is a sequence that starts at 0, then 1.
The next number is always the sum of the previous 2, for example:

0, 1, 1, 2, 3, 5, 8, 13 and so on...

This script will let the user get the nth term of this sequence.
'''

def fib(number):
    if number == 1:
        return 0
    elif number == 2:
        return 1
    else:
        return fib(number-1) + fib(number-2)

'''
Explanation:

The fib function works using recursion. Recursion put simply, is when a function calls() itself.

If the number passed to the function is greater than 2, it will return fib(number-1) + fib(number-2)
'''

if len(argv) < 2 or int(argv[-1]) == 0:
    #argv is a variable that just holds all the arguments passed to the system.
    #we want at least one extra so we only print this message if argv is less than 2 :)
    print("Usage: ./Fibonacci.py <nth term bigger than 0>")
    exit()
else:
    n = fib(int(argv[1]))
    print(n)
/*
 * Author : Karthikeyan_01
 * Algo : Fibonacci
*/



#include <bits/stdc++.h>

int fib(int n){
	if( n <= 1)
		return n;
	
	return fib(n - 1) + fib(n - 2);
}


int main(){

	int n = 10;
	std :: cout << fib(n);

	return 0;
}


/*
 * Input: 10
 * Output: 55
*/

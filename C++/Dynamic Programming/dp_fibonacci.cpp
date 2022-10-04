
/**
 * Author: Ahmed Elsisy
 * Date: 23/10/2020
 * Description: Given N and M , returns Nth fibonacci number modulus positive number M
 *
 * Memory: O(N)
 * Time: O(N) using dynamic programming for pre-processing and O(1) for query nth fibonacci number
 * Status: stress-tested for n <= 500000 (accepted on https://www.spoj.com/problems/FIBEZ/)
 */


class fibonacci_dp{
private:
   vector<int> fib;
   int mod;
   int add_mod(int x , int y){      // returns (x+y) % mod
      return (1ll * x + y) % mod;
   }
   void pre_process(){              // bottom-up dynamic programming fib(n) = (fib(n-1) + fib(n-2)) % mod
      int n = (int)fib.size();
      if(n >= 1)fib[0] = 1;
      if(n >= 2)fib[1] = 1;
      for(int i = 2 ; i < n ; ++i) {
         fib[i] = add_mod(fib[i - 1], fib[i - 2]);
      }
   }
public:
   fibonacci_dp(int maximum_N , int M){   // initialized
      mod = M;
      fib.resize(maximum_N + 1);
      pre_process();
   }
   int fibonacci(int n){            // returns nth fibonacci number
      return fib[n];
   }
};


/*
 * fib(0) = 0
 * fib(1) = 1
 * fib(2) = 1
 * fib(3) = 2
 * fib(4) = 3
 * fib(5) = 5
 * fib(6) = 8
 * fib(7) = 13
 * fib(8) = 21
 * fib(9) = 34
 * fib(10) = 55
 */

/**
 * Author: Ahmed Elsisy
 * Date: 20/10/2020
 * Description: Given N and R returns N choose R (how many ways to choose R elements from N elements)
 * using pre-processing factorials and inverse of factorials and answering nCr in O(1), just pass to the constructor
 * maximum N you will query for and prime number as a mod
 *
 * Memory: O(N)
 * Time: O(N) for pre-processing factorials and O(1) for answering query nCr(N,R)
 * Status: stress-tested for n <= 200000
 */
class nCr_mod{
private:
   vector<int> factorial;                 // (i!) % mod for all i less than max_n
   vector<int> inverse_factorial;         // (1 / (i!)) % mod for all i less than max_n
   int mod , max_n;
   int multiply_mod(int x , int y){                // returns x*y % mod
      return (1LL * (x % mod) * (y % mod)) % mod;
   }
   int power_mod(int x , int y){          // returns x^y % mod
      if(y == 0)return 1;
      if(y % 2 == 1)return multiply_mod(x , power_mod(x , y - 1));
      int r = power_mod(x , y / 2);
      return multiply_mod(r , r);
   }
   void pre_process() {                         // pre-processing factorial,inverse_factorial vectors by their values
      factorial.resize(max_n);
      inverse_factorial.resize(max_n);
      factorial[0] = inverse_factorial[0] = 1;
      for (int i = 1; i < max_n; ++i)
         factorial[i] = multiply_mod(i % mod, factorial[i - 1]);

      inverse_factorial[max_n - 1] = power_mod(factorial[max_n - 1], mod - 2);
      for (int i = max_n - 2; i >= 0; --i)
         inverse_factorial[i] = multiply_mod(inverse_factorial[i + 1], (i + 1) % mod);
   }
public:
   nCr_mod(int maximum_N , int prime_mod){
      mod = prime_mod;
      max_n = maximum_N + 1;
      pre_process();
   }
   int nCr(int N , int R){                // returns nCr (how many ways to choose R objects from N objects) which is equal to (N! / ((N - R)! * R!)
      if(R < 0 || R > N)return 0;
      int value = multiply_mod(factorial[N] , inverse_factorial[R]);
      return multiply_mod(value , inverse_factorial[N - R]);
   }
};

/*
 * input: nCr(5,3)
 * output: 10
 * nCr(5,3) = 5! / (2! * 3!) = 10
 */
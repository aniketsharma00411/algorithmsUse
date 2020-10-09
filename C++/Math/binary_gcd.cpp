/* BAAHUBALI7781  */
 
/*This Algorithm calculates Greatest Common Divisor of two non-negative intergers in O((logn)^2) worst time complexity*/

#include <bits/stdc++.h>
using namespace std;

int bin_gcd(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)       
        return a;
    if(a%2==0 && b%2==0)
        return 2*bin_gcd(a/2,b/2);
	else if(b%2==0)
		return bin_gcd(a,b/2);
	else if(a%2==0)
		return bin_gcd(a/2,b);
	else if(a&1 && b&1 && a>=b)
    	return bin_gcd((a-b)/2,b);
    else    
        return bin_gcd(a,(b-a)/2);

    
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<bin_gcd(a,b);
}
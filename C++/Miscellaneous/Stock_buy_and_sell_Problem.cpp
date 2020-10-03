//The cost of stock on each day is given in an array A[] of size N.
//Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
// Time Complexity : O(N)

#include <bits/stdc++.h>
using namespace std;
void StockBuySell(int price[], int n)
{
    if (n == 1)
        return;
    int i = 0;
    while (i < n - 1)
    {
        while ((i < n - 1) && (price[i + 1] <= price[i]))
            i++;
        if (i == n - 1)
            break;
        int buy = i++;
        while ((i < n) && (price[i] >= price[i - 1]))
            i++;
        int sell = i - 1;
        cout<<"Buy on day: "<<buy<<"\t Sell on day: "<<sell<<endl;
    }
}
int main()
{
    int price[]={ 100, 180, 260, 310, 40, 535, 695 };
    int n = sizeof(price)/sizeof(price[0]);
    stockBuySell(price, n);
    return 0;
}

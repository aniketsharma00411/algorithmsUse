//Given a sequence of matrices, find the most efficient way
//to multiply these matrices together. The problem is not
//actually to perform the multiplications, but merely to decide
//in which order to perform the multiplications.


#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int dp[N][N];

int MatrixChainMulitiplication(int p[], int i, int j)
{
    if (i == j)
        return 0;

    if (~dp[i][j])
        return dp[i][j];
    int k;
    int min = INT_MAX;
    int count;

    // place parenthesis at different places
    // between first and last matrix, recursively
    // calculate count of multiplications for
    // each parenthesis placement and return the
    // minimum count
    for (k = i; k < j; k++)
    {
        count = MatrixChainMulitiplication(p, i, k)
                + MatrixChainMulitiplication(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    // Return minimum count
    return dp[i][j] = min;
}



int main()
{
   memset(dp,-1,sizeof dp);
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << MatrixChainMulitiplication(arr,1, n - 1);
}

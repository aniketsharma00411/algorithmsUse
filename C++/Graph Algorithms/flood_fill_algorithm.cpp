/*
FLOOD FILL ALGORITHM : 
TIME COMPLEXITY : O(n^2)

Given a 2D screen arr[][] where each arr[i][j] is an integer representing the colour of that pixel, also given the location of a pixel (X, Y) and a colour C,
 the task is to replace the colour of the given pixel and all the adjacent same-coloured pixels with the given colour.

Example:

Input: arr[][] = {
{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1}}
X = 4, Y = 4, C = 3
Output:
1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0
1 0 0 1 1 0 1 1
1 3 3 3 3 0 1 0
1 1 1 3 3 0 1 0
1 1 1 3 3 3 3 0
1 1 1 1 1 3 1 1
1 1 1 1 1 3 3 1
Explanation:
The values in the given 2D screen indicate colours of the pixels. X and Y are coordinates of the brush, C is the colour that should replace the previous colour
 on screen[X][Y] and all surrounding pixels with the same colour. Hence all the 2 are replaced with 3.
*/

#include <bits/stdc++.h>
using namespace std;

//check is for checking that if  moving direction is valid or not
bool check(int i, int j, int n, int m, vector<vector<bool>> visit)
{
    if (i < 0 || j < 0 || i >= n || j >= m || visit[i][j] == true)
        return false;
    return true;
}

//flood fill algorithm is implmented using dfs algorithms
void dfs(vector<vector<int>> &a, int i, int j, int pix, int k, int n, int m, vector<vector<bool>> &visit)
{
    if (check(i, j, n, m, visit) && a[i][j] == pix)
    {
        a[i][j] = k;
        visit[i][j] = true;
        dfs(a, i - 1, j, pix, k, n, m, visit);
        dfs(a, i + 1, j, pix, k, n, m, visit);
        dfs(a, i, j + 1, pix, k, n, m, visit);
        dfs(a, i, j - 1, pix, k, n, m, visit);
    }
}

int main()
{
    int n, m, isrc, jsrc, k;

    //n,m are rows and column of matrix a
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));

    //visited matrix to check of the vertes is previuosly visited or not
    vector<vector<bool>> visit(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    //isrc , jsrc  are sourc element indices
    // k is the value with whch the pixel to be replaced
    cin >> isrc >> jsrc >> k;

    //dfs algorithm
    dfs(a, isrc, jsrc, a[isrc][jsrc], k, n, m, visit);

    //printing the resultant matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

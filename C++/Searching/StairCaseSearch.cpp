//stair case search is applied on the sorted matrix
//example - 1 2 3
//          4 5 6
//          7 8 9
#include <iostream>
using namespace std;
int main() {
    int m, n;
    int i, j;
    cout << "Enter the no. of rows and columns" << endl;
    //Taking input the number of rows and columns
    cin >> m >> n;
    int a[m][n];
    cout << "Enter the elements of the matrix:" << "\n";
    //taking input the elements of the matrix
    for ( i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];

        }
    }
    cout << "Enter the no. to be searched" << endl;
    int x;
    cin >> x;
    i = 0;
    j = n - 1;
    int pass = 0;
    //Initailly we will check the last element of every row if its smaller than the required
    //number we will keep on decrementing in the last column.
    //else we will traverse the row where the last element is greaterthan the required number.
    while (i < m && j < n) {
        if (a[i][j] == x) {
            pass = 1;
            break;
        }
        else if (x < a[i][j]) {
            j--;

        }
        else {
            i++;
        }
    }
    if (pass == 1)
        cout << "No. found at row = " << i + 1 << " & " << "column = " << j + 1 << endl;
    return 0;
}
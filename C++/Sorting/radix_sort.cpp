#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void PrintArray(vector<int> &arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

int getMax(vector<int> &arr)
{
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        mx = max(mx, arr[i]);
    return mx;
}

void countSort(vector<int> &arr, int exp)
{
    vector<int> output(arr.size(), 0);
    int i, count[10] = {0};

    for (i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = arr.size() - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

void RadixSort(vector<int> &arr)
{
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main(int args, char **argv)
{
    int n;
    cout << "Enter size of Array:";
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        arr[i] = (rand() % 10000) + 1; //Creates a array with Randomly generated Integers upto 10000

    cout << "Initial Array:" << endl;
    PrintArray(arr);

    RadixSort(arr);

    cout << "Array after sorting:" << endl;
    PrintArray(arr);

}
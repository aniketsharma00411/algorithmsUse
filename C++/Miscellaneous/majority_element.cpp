//moores voting algorithm to find majority element in an array
//contributed by devanshi katyal
#include <iostream>

using namespace std;
int findCanditate(int a[], int s)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < s; i++)
    {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}
bool ismajority(int a[], int size, int cand)
{
    int co = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == cand)
        {
            co++;
        }
    }
    if (co > (size / 2))
        return true;
    else
        return false;
}
int main()
{
    int n = 0;
    int a[n];
    cout << "Enter the size of array" << endl;
    cin >> n;
    cout << "Enter the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cand = findCanditate(a, n);
    if (ismajority(a, n, cand))
        cout << cand << " is the majority element";
    else
        cout << " no majority element";
    return 0;
}

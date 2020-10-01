//Program to calculate factorial of integers greater than 20
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
void fact(int);
int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;
    arr.clear();
    arr.push_back(1);
    fact(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[arr.size() - i - 1];
    }
    cout << endl;
    return 0;
}

void fact(int n)
{
    if (n != 1)
    {
        int carry = 0, test;
        for (int i = 0; i < arr.size(); i++)
        {
            test = ((n * arr[i]) + carry) % 10;
            carry = ((n * arr[i]) + carry) / 10;
            arr[i] = test;
        }
        if (carry != 0)
        {
            if (carry < 10)
            {
                arr.push_back(carry);
            }
            else
            {
                arr.push_back(carry % 10);
                arr.push_back(carry / 10);
            }
        }
        fact(n - 1);
    }
}
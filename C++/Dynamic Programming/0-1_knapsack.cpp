//
//Given a set of items, each with a weight and a value, 
//determine which items to include in a collection 
//so that the total weight is less than or equal to a given limit 
//and the total value is as large as possible.



#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int weight[N];
int value[N];

//n is the number of items and m is the total capacity of items we can take
int n, m;

int knapsack(int i = 0, int c = m) {

    if (i == n || c == 0)
        return 0;
    int choice1 = 0, choice2 = 0;
    // we can take this ith item if its weight less than or equal the current capacity or we can skip it 
    if (weight[i] <= c) {
        choice1 = value[i] + knapsack(i + 1, c - weight[i]);
    }
    choice2 = knapsack(i + 1, c);
    return max(choice1, choice2);

}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> value[i];
    for (int i = 0; i < n; ++i)
        cin >> weight[i];

    cout << knapsack() << endl;


}

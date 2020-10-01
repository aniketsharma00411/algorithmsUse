#include <bits/stdc++.h>

using namespace std;

int linearSearch(int arr[], int n, int key) {
  for (int i = 0;i < n;i++)
    if (arr[i] == key)return i;

  return -1;

  }

int main() {

  int n;cin >> n;//size of the array
  int arr[100005];
  for (int i = 0;i < n;i++)cin >> arr[i];//taking input inside the array
  int key;cin >> key;//the value which is to be find
  int ans = linearSearch(arr, n, key);
  if (ans == -1)  cout << "Element is not present in array" << endl;
  else cout << "Element is present at index " << ans << endl;

  return 0;

  }
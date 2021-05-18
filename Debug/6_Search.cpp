#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Corrected code
bool search(vector<int> arr, int n, int target)
{
    int left = 0, right = n - 1;
    int mid = left + (right - left) / 2;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

// Do not modify the code below
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (search(arr, n, target))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
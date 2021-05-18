#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> merge(vector<int> arr1, vector<int> arr2, int m, int n)
{
    vector<int> arr3(m + n);
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    return arr3;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> arr1(m), arr2(n);
    for (int i = 0; i < m; i++)
        cin >> arr1[i];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    vector<int> arr3 = merge(arr1, arr2, m, n);
    int size = m + n;
    for (int i = 0; i < size; i++)
        cout << arr3[i] << " ";
    return 0;
}
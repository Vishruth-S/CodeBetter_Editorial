#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] % K == 0)
            sum += arr[i];
    }
    cout << sum;
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int lastDigit = n % 10;
    cout << lastDigit;
    return 0;
}
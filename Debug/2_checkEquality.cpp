#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b and b == c)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
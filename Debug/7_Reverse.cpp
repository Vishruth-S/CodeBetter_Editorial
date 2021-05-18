#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// corrected code
string reverseStr(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}

// Do not modify the code below
int main()
{
    string s;
    cin >> s;
    cout << reverseStr(s);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string maximumOddBinaryNumber(string s)
{
    int n = s.length();
    sort(s.rbegin(), s.rend());
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            swap(s[i], s[n - 1]);
            break;
        }
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << maximumOddBinaryNumber(s) << endl;
}
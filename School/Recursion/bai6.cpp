#include <bits/stdc++.h>
using namespace std;

string bai6(string s, int n)
{
    if (n < 1)
        return "";
    return s[n - 1] + bai6(s, n - 1);
}

int main()
{
    string s = "luongngando";
    cout << bai6(s, s.length());
}
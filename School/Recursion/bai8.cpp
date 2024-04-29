#include <bits/stdc++.h>
using namespace std;

string reversed(string s, int n)
{
    if (n < 1)
        return "";
    return s[n - 1] + reversed(s, n - 1);
}

bool bai8(string &s, int n)
{
    if (n < 1)
        return "";
    string newString = s;
    for (int i = 0; i < s.length(); i++)
    {
        if (reversed(newString, newString.length()) == s)
            return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << boolalpha << bai8(s, s.length()) << endl;
}
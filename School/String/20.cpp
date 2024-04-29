#include <bits/stdc++.h>
using namespace std;

bool check(string &s)
{
    int l = 0;
    int r = s.length() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int TRY(string &s)
{
    int res = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            string subString = s.substr(i, j - i + 1);
            if (check(subString) && subString.length() > res)
            {
                res = subString.length();
            }
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << TRY(s) << endl;
}

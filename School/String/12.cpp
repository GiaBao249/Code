#include <bits/stdc++.h>
using namespace std;
// 1-345-789
string Try(string &s)
{
    string res = "";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        res += s[i];
        if ((s[i] - '0') % 2 && (s[i + 1] - '0') % 2)
            res += '-';
    }
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    cout << Try(s);
}
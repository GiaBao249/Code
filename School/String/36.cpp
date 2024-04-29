#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    bool ok;
    for (int i = 0; i < s.size(); i++)
    {
        int j = i + 1;
        if (s[i] == s[j])
            ok = true;
    }
    if (ok)
        cout << 1;
    else
        cout << 0;
}
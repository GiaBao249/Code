#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    string res = "";
    for (int i = 0; i < s.size(); i++)
        res += (s[i] ^ t[i]) + '0';
    cout << res << endl;
}
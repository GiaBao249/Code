#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = s[i] + 1;
        res += s[i];
    }
    cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]) && !isspace(s[i]))
            res += s[i];
    }
    cout << res;
}
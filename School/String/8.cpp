#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i + 1] == ' ' || s[i + 1] == '\0')
            res++;
    }
    cout << res << endl;
}
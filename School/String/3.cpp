#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int res = 0;
    for (char i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            res = i;
            break;
        }
    }
    cout << res << endl;
    s[res] = s[res] - 32;
    for (int i = res + 1; i < s.size(); i++)
    {
        if (s[i - 1] == ' ' && s[i] != ' ')
        {
            s[i] = s[i] - 32;
        }
    }
    cout << s;
}
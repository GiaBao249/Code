#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    bool ok = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0' && s[i] == s[i + 1] || s[i] == '1' && s[i] == s[i + 1])
        {
            cnt++;
            if (cnt == 6 && s[i] == s[i + 1])
            {
                ok = true;
                break;
            }
        }
        else
        {
            cnt = 0;
        }
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool ok = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
        {
            ok = false;
            break;
        }
    }
    if (ok)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
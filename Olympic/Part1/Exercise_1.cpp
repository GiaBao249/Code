#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.size() < 10)
            cout << s << endl;
        else
            cout << s[0] << s.size() - 2 << s.back() << endl;
    }
}
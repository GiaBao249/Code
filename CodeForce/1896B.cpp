#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int res = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
                res--;
            else
                break;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'A')
                res--;
            else
                break;
        }
        if (res >= 0)
            cout << res << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
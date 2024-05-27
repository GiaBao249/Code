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
        string s, f;
        cin >> s >> f;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && f[i] == '1')
                cnt1++;
            else if (s[i] == '1' && f[i] == '0')
                cnt2++;
        }
        // int sum = min(cnt1, cnt2) + abs(cnt1 - cnt2);
        int sum = max(cnt1, cnt2);
        cout << sum << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
            v.push_back(i);
    }
    int cnt = 0;
    int trance = 0, res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
        {
            trance++;
            cnt++;
        }
        else if (s[i] == ']')
        {
            --cnt;
        }
        if (cnt < 0)
        {
            res += v[trance] - i;
            swap(s[i], s[v[trance]]);
            cnt = 1;
            ++trance;
        }
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;

// using ll = long long;

bool cmp(pair<char, int> a, pair<char, int> b) { return a.second > b.second; }

void solve()
{
    int d;
    cin >> d;
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> mp;
    for (char x : s)
        mp[x]++;
    vector<pair<char, int>> v;
    for (auto it : mp)
    {
        v.push_back(it);
    }
    sort(v.begin(), v.end(), cmp);
    string res = string(n, ' ');
    bool ok = true;
    for (int i = 0; i < v.size(); i++)
    {
        int pos = i;
        while (res[pos] != ' ')
            ++pos;
        for (int k = 0; k < v[i].second; k++)
        {
            if (pos + k * d >= n)
            {
                ok = false;
                break;
            }
            else
            {
                res[pos + k * d] = v[i].first;
            }
        }
    }
    if (!ok)
    {
        cout << -1 << endl;
    }
    else
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
    return 0;
}
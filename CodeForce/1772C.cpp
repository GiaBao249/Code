#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    string a[3][n];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }
    vector<int> res;
    for (int i = 0; i < 3; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (mp[a[i][j]] == 1)
                cnt += 3;
            else if (mp[a[i][j]] == 2)
                cnt++;
        }
        res.push_back(cnt);
    }
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 0;
/*
 /\_/\
(= >_<)
/ >  \>
*/
void Solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    f0(i, n) cin >> a[i];
    unordered_map<int, int> mp;
    ll s = 0, cnt = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        if (mp.count(s - x))
            cnt += mp[s - x];
        mp[s]++;
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
    Solve();
    return 0;
}
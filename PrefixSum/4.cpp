#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 0;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> // tìm dãy con nhỏ nhất có tổng bằng k
*/
void Solve()
{
    int n , k; cin >> n >> k;
    vector<int> a(n);
    f0(i ,n) cin >> a[i];
    vector<ll> pre(n + 1);
    pre[1] = a[0];
    int res = inf;
    for(int i = 1 ; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    unordered_map<int , int> mp;
    f0(i ,n)
    {
        if(mp.count(pre[i] - k))
        {
            res = min(res, i - mp[pre[i] - k] + 1);
        }
        mp[pre[i]] = i + 1;
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

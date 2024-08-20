#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
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
/ >  \> https://cses.fi/problemset/task/1638/
*/
int n;
vector<vector<char>> a;
vector<vector<ll>> memo;
ll dfs(int i, int j)
{
    if (i >= n || j >= n || a[i][j] == '*')
        return 0;
    if (i == n - 1 && j == n - 1)
        return 1;
    if (memo[i][j] != -1)
        return memo[i][j];
    ll r = dfs(i, j + 1);
    ll c = dfs(i + 1, j);
    memo[i][j] = (r + c) % MOD;
    return memo[i][j];
}

void Solve()
{
    cin >> n;
    a.resize(n, vector<char>(n));
    memo.resize(n, vector<ll>(n, -1));
    f0(i, n) f0(j, n) cin >> a[i][j];
    cout << dfs(0, 0);
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
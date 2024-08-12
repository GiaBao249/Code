#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define inf INT_MAX
const int maxn = 200005;
/*
 /\_/\
(= ._.)
/ >  \> https://codeforces.com/problemset/problem/1999/E
*/
vector<int> pre(maxn), dp(maxn);
int sum(int n)
{
    int res = 0;
    while (n > 0)
    {
        res++;
        n /= 3;
    }
    return res;
}

void Run()
{
    f0(i, maxn - 1)
    {
        dp[i] = sum(i);
        pre[i + 1] = pre[i] + dp[i];
    }
}

void Solve()
{
    int l, r;
    cin >> l >> r;
    cout << pre[r + 1] - pre[l] + dp[l] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t;
    cin >> t;
    Run();
    while (t--)
        Solve();
    return 0;
}
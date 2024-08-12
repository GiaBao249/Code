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
const int maxn = 300005;
/*
 /\_/\
(= ._.)
/ >  \> https://codeforces.com/contest/356/problem/A
*/
vector<int> par(maxn), res(maxn);

int get(int x) { return par[x] == x ? x : (par[x] = get(par[x])); }

void unite(int a, int b)
{
    a = get(a);
    b = get(b);
    if (a != b)
        par[b] = a;
}
void Solve()
{
    int n, k;
    cin >> n >> k;

    par.resize(n + 2);
    res.resize(n + 2, 0);

    for (int i = 1; i <= n + 1; i++)
        par[i] = i;

    while (k--)
    {
        int l, r, x;
        cin >> l >> r >> x;

        int i = get(l);
        while (i < x)
        {
            res[i] = x;
            unite(x, i);
            i = get(i + 1);
        }

        i = get(x + 1);
        while (i <= r)
        {
            res[i] = x;
            unite(get(r + 1), i);
            i = get(i + 1);
        }
    }

    f1(i, n) i == get(i) ? cout << 0 << " " : cout << res[i] << " ";
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
    Solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 0;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1745/
*/

set<int> se;
int n;
bool visited [105][200005];

vector<ll> a(n);
void dfs(int i, int s)
{
    if(i >= n) {
        se.insert(s);
        return;
    }
    if(visited[i][s]) {
        return;
    }
    dfs(i + 1, s + a[i]);
    dfs(i + 1, s);
    visited[i][s] = 1;
}

void Solve()
{
    cin >> n;
    a.resize(n);
    f0(i, n) cin >> a[i];
    dfs(0,0);
    se.erase(0);
    cout << sz(se) << el;
    for(auto x : se)
        cout << x << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

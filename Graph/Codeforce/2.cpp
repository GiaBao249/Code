#include <bits/stdc++.h>
using namespace std;
#define ll long long
using vl = vector<ll>;
#define pb push_back
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 20004;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://codeforces.com/contest/520/problem/B
*/
int n, m;
vector<vl> a(maxn);
int d[maxn];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    d[u] = 1;
    while(sz(q)) {
        int v = q.front();
        q.pop();
        for(auto x : a[v]) {
            if(!d[x]) {
                q.push(x);
                d[x] = d[v] + 1;
            }
        }
    }
}

void Solve()
{
    cin >> n >> m;
    f1(i , 10000) {
        a[i].pb(i * 2);
        a[i].pb(i - 1);
    }
    bfs(n);
    cout << d[m] - 1 << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

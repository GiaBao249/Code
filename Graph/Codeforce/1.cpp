#include <bits/stdc++.h>
using namespace std;
#define ll long long
using vl = vector<ll>;
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 10004;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://codeforces.com/problemset/problem/755/C
*/
int n , cnt = 0;
vector<vl> a(maxn);
int d[maxn];
void dfs(int u)
{
    d[u] = 1;
    for(auto x : a[u]){
        if(!d[x]){
            dfs(x);
        }
    }
}
void Solve()
{
    cin >> n;
    f1(i , n)
    {
        int x ;cin >> x;
        a[x].push_back(i);
        a[i].push_back(x);
    }
    f1(i , n)
    {
        if(!d[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

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
const int maxn = 1005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n,m;
int a[maxn][maxn], vis[maxn][maxn];
void dfs(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 1 || vis[i][j])
        return;
    vis[i][j] = 1;
    f0(k, 4) {
        int u = i + dx[k] , v = j + dy[k];
        dfs(u , v);
    }
}
void Solve()
{
    cin >> n >> m;
    f0(i , n)
    {
        f0(j , m)
        {
            char c ; cin >> c;
            if(c == '#')
                a[i][j] = 1;
            else
                a[i][j] = 0;
            vis[i][j] = 0;
        }
    }
    int res = 0;
    f0(i , n)
    {
        f0(j , m){
            if(a[i][j] == 0 && !vis[i][j]){
            dfs(i , j);
            res++;
            }
        }
    }
    cout << res << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define inf INT_MAX
#define maxn 1005
/*
 /\_/\
(= ._.)
/ >  \> https://codeforces.com/contest/1829/problem/E
*/

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
vector<vector<int>> visited(maxn, vector<int>(maxn, 0));
int a[maxn][maxn];

int bfs(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || a[i][j] == 0)
        return 0;
    visited[i][j] = 1;
    int s = a[i][j];
    f0(k, 4)
    {
        int u = i + dx[k], v = j + dy[k];
        s += bfs(u, v, n, m);
    }
    return s;
}

int Check(int n, int m)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && a[i][j] != 0)
                s = max(s, bfs(i, j, n, m));
        }
    }
    return s;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    f0(i, n)
    {
        f0(j, m)
        {
            cin >> a[i][j];
            visited[i][j] = 0;
        }
    }

    cout << Check(n, m) << endl;
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
    while (t--)
        Solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}
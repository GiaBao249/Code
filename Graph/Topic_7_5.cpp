#include <bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<pair<int, int>> vp;
vector<int> v[1005];
int n, m, u, s, t;

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        vp.push_back({x, y});
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

void DFS(int u, int s, int t)
{
    visited[u] = true;
    for (auto it : v[u])
    {
        if (u == s && t == it || u == t && it == s)
            continue;
        if (!visited[it])
        {
            DFS(it, s, t);
        }
    }
}

int tplt(int s, int t)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            DFS(i, s, t);
        }
    }
    return cnt;
}

int main()
{
    Input();
    int cc = tplt(0, 0);
    int cnt = 0;
    for (auto it : vp)
    {
        int x = it.first, y = it.second;
        memset(visited, false, sizeof(visited));
        if (cc < tplt(x, y))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}
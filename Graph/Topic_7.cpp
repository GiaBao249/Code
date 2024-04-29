#include <bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<pair<int, int>> v;
set<int> se[1005];
int n, m;

void Input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        se[x].insert(y);
        se[y].insert(x);
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (auto x : se[u])
    {
        if (!visited[x])
        {
            DFS(x);
        }
    }
}

int tplt()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ++cnt;
            DFS(i);
        }
    }
    return cnt;
}

int main()
{
    Input();
    int cc = tplt();
    int cnt = 0;
    for (auto it : v)
    {
        int x = it.first, y = it.second;
        se[x].erase(y);
        se[y].erase(x);
        memset(visited, false, sizeof(visited));
        if (cc < tplt())
        {
            ++cnt;
        }
        se[x].insert(y);
        se[y].insert(x);
    }
    cout << cnt << endl;
}
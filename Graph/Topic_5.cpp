#include <bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> v[1005];
int parent[1005];
int n, m, s, t;
void DFS(int u)
{
    visited[u] = true;
    for (auto x : v[u])
    {
        if (!visited[x])
        {
            DFS(x);
            parent[x] = u;
        }
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i : v[x])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = x;
            }
        }
    }
}

void Input()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

int main()
{
    Input();
    BFS(s);
    if (!visited[t])
        return -1;
    else
    {
        vector<int> res;
        while (t != s)
        {
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for (auto x : res)
        {
            cout << x << " ";
        }
    }
}
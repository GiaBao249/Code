#include <bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> v[1005];
int parent[1005];
int n, m, u, s, t;

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

bool DFS(int u)
{
    visited[u] = true;
    for (auto x : v[u])
    {
        if (!visited[x])
        {
            parent[x] = u;
            if (DFS(x))
                return true;
        }
        else if (x != parent[u])
        {
            return true;
        }
    }
    return false;
}

bool BFS(int u)
{
}

int main()
{
    Input();
    if (DFS(1))
        cout << "Yes" << endl;
    else
        cout << "No " << endl;
}
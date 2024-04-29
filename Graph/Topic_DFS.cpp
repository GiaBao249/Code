#include <bits/stdc++.h>
using namespace std;

vector<int> v[1001];

bool visited[1001];

int a[1001][1001];
int n, m;
vector<pair<int, int>> dsc;
// Danh sách kề
int DFS1(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int x : v[u])
    {
        if (!visited[x])
            DFS1(x);
    }
}

// Ma trận kề
int DFS2(int u)
{
    cout << u << " ";
    visited[u] = true;
    // duyet danh sach ke tu dinh cua u : duyet dong thu u cua ma tran ke a
    for (int i = 1; i <= n; i++)
    {
        if (a[u][i] == 1)
        {
            if (!visited[i])
                DFS2(i);
        }
    }
}

// Danh sách cạnh
int DFS3(int u)
{
    cout << u << " ";
    visited[u] = true;
    // duyet danh sach ke tu dinh u
    for (auto it : dsc)
    {
        if (it.first == u)
        {
            if (!visited[it.second])
            {
                DFS3(it.second);
            }
        }
        if (it.second == u)
        {
            if (!visited[it.first])
            {
                DFS3(it.first);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS1(1);
}
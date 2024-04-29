#include <bits/stdc++.h>
using namespace std;

vector<int> v[1001];
bool visited[1001];
int n, m;
int DFS(int u)
{
    visited[u] = true;
    for (int x : v[u])
    {
        if (!visited[x])
            DFS(x);
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
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}
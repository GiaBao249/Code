#include <bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<int> v[1005];
int id[1001];
int cnt = 0, n, m;
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        id[x] = cnt;
        for (int it : v[x])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
}

void Input()
{
    cin >> n >> m;
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
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ++cnt;
            BFS(i);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (id[x] == id[y])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

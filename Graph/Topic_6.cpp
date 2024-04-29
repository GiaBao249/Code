#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[1005];
bool visited[1005];

int tplt()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}

void dinh_tru()
{
    int it = tplt();
    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if (it > tplt())
        {
            cout << i << endl;
        }
    }
}

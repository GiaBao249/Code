#include <bits/stdc++.h>
using namespace std;

// Chuyển danh sách cạnh thành danh sách kề (vô hướng)

vector<int> v[1005];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());
        cout << i << " ";
        for (int x : v[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <math.h>
#define ll long long
using namespace std;

void Solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    set<char> x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (i == j || i == n - j - 1)
                x.insert(a[i][j]);
            else
                y.insert(a[i][j]);
        }
    }
    if (x.size() == 1 && y.size() == 1 && *x.begin() != *y.begin())
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
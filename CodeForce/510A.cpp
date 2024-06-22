#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cstring>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v[i][j] = '.';
        }
    }
    int J = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                v[i][j] = '#';
            }
        }
    }
    int cnt = 2;
    for (int i = 1; i < n; i += 2)
    {
        if (i < cnt)
        {
            v[i][m - 1] = '#';
        }
        else
        {
            v[i][0] = '#';
            cnt += 4;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << v[i][j];
        cout << endl;
    }
    return 0;
}
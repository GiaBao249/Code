#include <bits/stdc++.h>
using namespace std;

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
vector<vector<int>> largestLocal(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> maxLocal;
    for (int i = 1; i < n - 1; i++)
    {
        vector<int> save;
        for (int j = 1; j < n - 1; j++)
        {
            int max_val = INT_MIN;
            for (int k = 0; k < 9; ++k)
            {
                int u = i + dx[k];
                int v = j + dy[k];
                if (u >= 0 && u < n && v >= 0 && v < n)
                    max_val = max(max_val, grid[u][v]);
            }
            save.push_back(max_val);
        }
        maxLocal.push_back(save);
    }
    return maxLocal;
}

int main()
{
    // Example input grid
    vector<vector<int>> grid = {
        {1, 3, 1, 8, 9},
        {1, 1, 1, 1, 1},
        {1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1},
        {2, 1, 1, 1, 7}};

    // Compute maxLocal
    vector<vector<int>> result = largestLocal(grid);

    // Print the result
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
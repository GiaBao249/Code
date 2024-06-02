#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool DFS(vector<vector<char>> &a, vector<vector<bool>> &b, string &word, int u, int v, int index)
{
    int n = a.size();
    int m = a[0].size();
    if (index == word.size())
        return true;
    if (u >= n || v >= m || v < 0 || u < 0 || word[index] != a[u][v] || b[u][v])
        return false;

    b[u][v] = true;
    for (int k = 0; k < 4; k++)
    {
        int x = u + dx[k];
        int y = v + dy[k];
        if (DFS(a, b, word, x, y, index + 1))
            return true;
    }
    b[u][v] = false;
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();
    if (n == 0)
        return false;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0] && DFS(board, visited, word, i, j, 0))
                return true;
        }
    }
    return false;
}
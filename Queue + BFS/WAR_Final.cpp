#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// Hàm kiểm tra xem có thể di chuyển đến ô mới hay không
bool isValidMove(const vector<vector<int>> &grid, const vector<vector<bool>> &visited, int row, int col)
{
    int rows = grid.size();
    int cols = grid[0].size();
    return (row >= 0 && row < rows && col >= 0 && col < cols &&
            grid[row][col] == 0 && !visited[row][col]);
}

// Hàm DFS để tìm kích thước của vùng an toàn
void dfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int &regionSize)
{
    visited[row][col] = true;
    regionSize++;

    static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (const auto &dir : directions)
    {
        int newRow = row + dir.first;
        int newCol = col + dir.second;
        if (isValidMove(grid, visited, newRow, newCol))
        {
            dfs(grid, visited, newRow, newCol, regionSize);
        }
    }
}

// Hàm tìm số lượng vùng an toàn và kích thước lớn nhất của vùng an toàn
pair<int, int> findSafeRegions(const vector<vector<int>> &grid)
{
    int rows = grid.size();
    if (rows == 0)
        return {0, 0}; // Nếu grid rỗng, trả về 0 vùng an toàn và kích thước lớn nhất là 0

    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int numRegions = 0;
    int largestRegion = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 0 && !visited[i][j])
            {
                int regionSize = 0;
                dfs(grid, visited, i, j, regionSize);
                numRegions++;
                largestRegion = max(largestRegion, regionSize);
            }
        }
    }

    return make_pair(numRegions, largestRegion);
}

// Hàm tìm đường đi ngắn nhất từ một ô an toàn cho trước đến biên
pair<int, vector<pair<int, int>>> findShortestExit(const vector<vector<int>> &grid, int startRow, int startCol)
{
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<pair<int, int>, vector<pair<int, int>>>> q;
    q.push({{startRow, startCol}, {{startRow, startCol}}});
    visited[startRow][startCol] = true;

    static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<pair<int, int>> path;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int row = curr.first.first;
        int col = curr.first.second;
        path = curr.second;

        if (grid[row][col] == 1)
            continue;
        if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1)
        {
            // Thuật toán đã tìm thấy đường đi thoát ra biên, trả về kết quả
            return make_pair(path.size(), path);
        }

        for (const auto &dir : directions)
        {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (isValidMove(grid, visited, newRow, newCol))
            {
                vector<pair<int, int>> newPath = path;
                newPath.push_back({newRow, newCol});
                q.push({{newRow, newCol}, newPath});
                visited[newRow][newCol] = true;
            }
        }
    }

    // Không tìm thấy đường đi thoát ra biên
    return make_pair(-1, path);
}

int main()
{
    int n, m, startRow, startCol;
    cin >> n >> m >> startRow >> startCol;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }

    pair<int, vector<pair<int, int>>> shortestExitPath = findShortestExit(grid, startRow - 1, startCol - 1);
    int shortestExit = shortestExitPath.first;
    vector<pair<int, int>> path = shortestExitPath.second;

    pair<int, int> regions = findSafeRegions(grid);

    cout << regions.first << " " << regions.second << " " << shortestExit - 1 << endl;

    if (shortestExit != -1)
    {
        // In đường đi thoát ra biên
        for (const auto &point : path)
        {
            cout << "(" << point.first + 1 << "," << point.second + 1 << ") ";
        }
        cout << endl;
    }

    return 0;
}

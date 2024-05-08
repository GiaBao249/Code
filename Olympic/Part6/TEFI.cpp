#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Hàm đếm số lượng kí tự T, E, F, I trong bảng
void count_TEFIGrid(vector<vector<int>> &grid, int n, int m, int &count_T, int &count_E, int &count_F, int &count_I)
{
    count_T = count_E = count_F = count_I = 0;

    // Đếm theo hàng
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m - 2; ++j)
        {
            if (grid[i][j] == 1 && grid[i][j + 1] == 1 && grid[i][j + 2] == 1)
            {
                if (j == 0 || grid[i][j - 1] == 0)
                {
                    count_T++;
                }
                else if (grid[i][j + 3] == 0)
                {
                    count_E++;
                }
            }
        }
    }

    // Đếm theo cột
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n - 2; ++i)
        {
            if (grid[i][j] == 1 && grid[i + 1][j] == 1 && grid[i + 2][j] == 1)
            {
                if (i == 0 || grid[i - 1][j] == 0)
                {
                    count_F++;
                }
                else if (grid[i + 3][j] == 0)
                {
                    count_I++;
                }
            }
        }
    }
}
int main()
{
    ifstream input("TEFI.inp");
    ofstream output("TEFI.out");

    int n, m;
    input >> n >> m;

    // Đọc dữ liệu từ file input
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            input >> grid[i][j];
        }
    }

    int count_T, count_E, count_F, count_I;
    // Đếm số lượng ký tự T, E, F, I trong bảng
    count_TEFIGrid(grid, n, m, count_T, count_E, count_F, count_I);

    // Ghi kết quả vào file output
    output << "T " << count_T << endl;
    output << "E " << count_E << endl;
    output << "F " << count_F << endl;
    output << "I " << count_I << endl;

    input.close();
    output.close();

    return 0;
}

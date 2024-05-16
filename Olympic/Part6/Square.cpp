#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream input("Square.inp");
    ofstream output("Square.out");

    int n;
    input >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            input >> grid[i][j];
        }
    }

    vector<vector<int>> dp1(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            dp1[i][j] = count;
        }
    }

    vector<vector<int>> dp2(n, vector<int>(n, 0));
    for (int j = 0; j < n; ++j)
    {
        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (grid[i][j] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            dp2[i][j] = count;
        }
    }

    int max_size = 0;
    pair<int, int> top_left, bottom_right;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int size = min(dp1[i][j], dp2[i][j]);
            for (int k = size; k > max_size; --k)
            {
                if (i + k - 1 < n && j + k - 1 < n && dp1[i + k - 1][j] >= k && dp2[i][j + k - 1] >= k)
                {
                    max_size = k;
                    top_left = make_pair(i, j);
                    bottom_right = make_pair(i + k, j + k);
                    break;
                }
            }
        }
    }
    int width = bottom_right.second - top_left.second + 1;
    int height = bottom_right.first - top_left.first + 1;

    output << width * height << endl;
    output << top_left.first << " " << top_left.second << " " << bottom_right.first << " " << bottom_right.second << endl;

    input.close();
    output.close();

    return 0;
}

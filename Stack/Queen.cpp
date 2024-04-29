#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;

bool check(vector<vector<int>> &v, int hang, int cot)
{
    for (int i = 0; i < hang; i++)
    {
        if (v[i][cot])
            return false;
    }
    for (int i = hang, j = cot; i >= 0 && j >= 0; i--, j--)
    {
        if (v[i][j])
            return false;
    }
    for (int i = hang, j = cot; i >= 0 && j < n; i--, j++)
    {
        if (v[i][j])
            return false;
    }
    return true;
}

void Print(vector<vector<int>> &v)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (v[i][j] ? "Q" : ".") << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Test(int &n, int hang, vector<vector<int>> &broad)
{
    stack<pair<int, int>> st;
    st.push({hang, 0});
    while (!st.empty())
    {
        int u = st.top().first;
        int v = st.top().second;
        st.pop();
        for (int i = v; i < n; i++)
        {
            if (check(broad, u, i))
            {
                broad[u][i] = 1;
                if (u == n - 1)
                {
                    Print(broad);
                    broad[u][i] = 0;
                }
                else
                {
                    st.push({u + 1, 0});
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    Test(n, 0, board);
    return 0;
}
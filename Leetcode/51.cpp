#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
bool check(vector<string> &v, int index, int n)
{
    if (v.empty())
        return true;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][index] == 'Q')
            return false;
    }
    int y = index - 1;
    int x = v.size() - 1;
    while (x >= 0 && y >= 0)
    {
        if (v[x][y] == 'Q')
            return false;
        x--;
        y--;
    }
    y = index + 1;
    x = v.size() - 1;
    while (x >= 0 && y < n)
    {
        if (v[x][y] == 'Q')
            return false;
        x--;
        y++;
    }
    return true;
}

void recursion(int n, string &s, vector<string> &v)
{
    if (v.size() == n)
    {
        ans.push_back(v);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(v, i, n))
        {
            s[i] = 'Q';
            v.push_back(s);
            s[i] = '.';
            recursion(n, s, v);
            v.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += '.';
    }
    vector<string> v;
    recursion(n, s, v);
    return ans;
}

int main()
{
    int n; // the size of the chessboard and the number of queens
    cout << "Enter the value of n: ";
    cin >> n; // input n from keyboard
    if (n <= 0)
    {
        cout << "Invalid input. n must be a positive integer.\n";
        return 1; // return non-zero value to indicate error
    }
    vector<vector<string>> result = solveNQueens(n); // call the function and store the result
    int count = result.size();                       // get the number of solutions
    if (count == 0)
    {
        cout << "There is no solution for n = " << n << ".\n";
    }
    else
    {
        cout << "There are " << count << " solutions for n = " << n << ".\n";
        for (int i = 0; i < count; i++)
        {
            cout << "Solution " << i + 1 << ":\n";
            for (string row : result[i])
            {
                cout << row << "\n";
            }
            cout << "\n";
        }
    }
    return 0; // return zero to indicate success
}
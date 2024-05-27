#include <bits/stdc++.h>
using namespace std;

void backtracking(vector<char> &a, int i, int j, int n, vector<string> &b)
{
    if (i == n && j == n)
    {
        string temp = "";
        for (auto x : a)
            temp += x;
        b.push_back(temp);
        return;
    }
    if (i < n)
    {
        a.push_back('(');
        backtracking(a, i + 1, j, n, b);
        a.pop_back();
    }
    if (j < i)
    {
        a.push_back(')');
        backtracking(a, i, j + 1, n, b);
        a.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<char> res;
    vector<string> b;
    backtracking(res, 0, 0, n, b);
    return b;
}

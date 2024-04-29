#include <bits/stdc++.h>
using namespace std;

int n, p, s, x[100];
vector<int> v;
vector<vector<int>> res;

int snt(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

void Input()
{
    cin >> n >> p >> s;
    for (int i = p + 1; i <= s; i++)
    {
        if (snt(i))
            v.push_back(i);
    }
}

void Try(int i, int sum, int pos)
{
    if (i == n && sum == s)
    {
        vector<int> tmp(x, x + n);
        res.push_back(tmp);
    }
    for (int j = pos; j < v.size(); j++)
    {
        if (sum + v[j] <= s)
        {
            x[i] = v[j];
            Try(i + 1, sum + v[j], j + 1);
        }
    }
}

int main()
{
    Input();
    Try(0, 0, 0);
    cout << res.size() << endl;
    for (auto it : res)
    {
        for (int x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

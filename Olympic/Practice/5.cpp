#include <bits/stdc++.h>
using namespace std;

void Test(int n, vector<int> &v, int max, int x)
{
    if (n == 0)
    {
        cout << x << " = " << v[0];
        for (int i = 1; i < v.size(); i++)
        {
            cout << " + " << v[i];
        }
        cout << endl;
    }
    else
    {
        for (int i = min(max, n); i >= 1; i--)
        {
            v.push_back(i);
            Test(n - i, v, i, x);
            v.pop_back();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    Test(n, a, n - 1, n);
    return 0;
}
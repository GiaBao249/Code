#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int res = INT_MIN;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        sum = sum + b - a;
        res = max(sum, res);
    }
    cout << res << endl;
}
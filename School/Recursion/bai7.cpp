#include <bits/stdc++.h>
using namespace std;

int bai7(float n, int m)
{
    if (m == 1)
        return n;
    else if (m >= 0)
        return n * bai7(n, m - 1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << bai7(n, m);
}
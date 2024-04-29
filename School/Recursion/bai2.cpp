#include <bits/stdc++.h>
using namespace std;

int bai2(int n)
{
    if (n == 0)
        return 1;
    return n * bai2(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << bai2(n);
}
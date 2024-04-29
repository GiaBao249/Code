#include <bits/stdc++.h>
using namespace std;

int bai3(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return bai3(n - 1) + bai3(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << bai3(n);
}
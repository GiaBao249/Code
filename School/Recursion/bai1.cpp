#include <bits/stdc++.h>
using namespace std;

int bai1(int n)
{
    if (n == 1)
        return 1;
    return n + bai1(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << bai1(n);
}

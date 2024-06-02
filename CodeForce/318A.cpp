#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    n = (n + 1) / 2;
    cout << (k > n ? 2 * (k - n) : 2 * k - 1);
}
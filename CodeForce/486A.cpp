#include <bits/stdc++.h>
using namespace std;

long long solve(long long n)
{
    long long s = 0;
    if (n % 2 == 0)
        return n / 2;
    return -(n / 2) - 1;
}

int main()
{
    long long n;
    cin >> n;
    cout << solve(n);
}
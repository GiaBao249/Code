#include <bits/stdc++.h>
using namespace std;

int arrangeCoins(int n)
{
    int cnt = 0;
    long sum = 0;
    if (n == 1 || n == 0)
        return n;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
        if (sum <= n)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    return cnt;
}
#include <bits/stdc++.h>
using namespace std;

int countBits(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        cnt += n & 1;
        n /= 2;
    }
    return cnt;
}

bool cmp(int a, int b)
{
    int x = countBits(a);
    int y = countBits(b);
    if (x == y)
    {
        return a <= b;
    }
    else
        return x < y;
}

vector<int> sortByBits(vector<int> &a)
{
    sort(a.begin(), a.end(), cmp);
    return a;
}
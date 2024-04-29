#include <bits/stdc++.h>
using namespace std;

int gt(int *n)
{
    int gt = 1;
    for (int i = 1; i <= (*n); i++)
    {
        gt *= i;
    }
    return gt;
}

int main()
{
    int n;
    cin >> n;
    int *a = &n;
    cout << gt(a) << endl;
}
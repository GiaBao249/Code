#include <bits/stdc++.h>
using namespace std;

int bai11(int a[], int val, int n)
{
    int count = 1;
    if (n == 0)
        return 0;
    if (a[n - 1] == val)
    {
        return count + bai11(a, val, n - 1);
    }
    else
    {
        return bai11(a, val, n - 1);
    }
}

int main()
{
    int a[] = {3, 4, 5, 7, 3, 9, 5, 3, 5, 9, 3, 4, 3, 5};
    int val = 7;
    cout << bai11(a, val, 14);
}
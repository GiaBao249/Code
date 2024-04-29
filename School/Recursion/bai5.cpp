#include <bits/stdc++.h>
using namespace std;

int bai5(int a[], int l, int r, int &max_val, int &min_val)
{
    if (l == r)
    {
        max_val = a[l];
        min_val = a[l];
    }
    if (l < r)
    {
        int mid = (l + r) / 2;
        int max1, max2, min1, min2;
        bai5(a, mid + 1, r, max1, min1);
        bai5(a, l, mid, max2, min2);
        max_val = max(max1, max2);
        min_val = min(min1, min2);
    }
}

int main()
{
    int n = 5, max, min;
    int a[] = {1, 2, 3, 5, 6};
    bai5(a, 0, n - 1, max, min);
    cout << "Gia tri max la " << max << endl;
    cout << "Gia tri min la " << min << endl;
}
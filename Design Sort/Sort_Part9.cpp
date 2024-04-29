#include <bits/stdc++.h>
using namespace std;

int BinarySeach1(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x)
        {
            res = mid;
            r = mid - 1; // Tìm phần tử xuất hiện đầu tiên trong mảng bằng BS
        }
        else if (a[mid] > x)
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}

int BinarySeach2(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == x)
        {
            res = mid;
            l = mid + 1; // Tìm phần tử cuối cùng trong mảng bằng BS
        }
        else if (a[mid] > x)
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}
int main()
{
    int a[100], n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i1 = BinarySeach1(a, n, x);
    int i2 = BinarySeach2(a, n, x);
    if (i1 != -1)
        cout << i2 - i1 + 1 << endl;
    else
        cout << "0" << endl;
}
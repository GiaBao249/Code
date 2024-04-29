#include <bits/stdc++.h>
using namespace std;

int BinarySeach1(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    int res = -1;
    while (l < r)
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
    while (l < r)
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

// Dùng hàm lower_bound => phần tử đầu tiên >= k nằm trong mảng
// Dùng hàm upper_bound => phần tử đầu tiên > k nằm trong mảng
void Func(int a[], int k)
{
    auto it = lower_bound(a, a + n, k);
    if (*it == k)
    {
        cout << it - a + 1 << endl;
    }
    cout << "-1\n";
}

int main()
{
    int n;
    cin >> n;
    int x, a[100];
    cin >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = BinarySeach1(a, n, x);
    if (res != -1)
        cout << res + 1 << endl;
    else
        cout << "-1" << endl;
}
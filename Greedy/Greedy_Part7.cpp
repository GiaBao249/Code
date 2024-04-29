#include <bits/stdc++.h>
using namespace std;

int a[100], n, ok = 1;

int solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(a, a + n);
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i] && a[i] != b[n - i - 1]) // kiểm tra xem vị trí của a[i] có trùng với mảng đã sắp xếp hay chưa và
        // vị trí đối xứng của a[i] qua b[i] nếu có thì có thể sắp xếp đc và in ra Yes
        {
            cout << "No" << endl;
            ok = 0;
            break;
        }
    }
    if (ok)
        cout << "Yes" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
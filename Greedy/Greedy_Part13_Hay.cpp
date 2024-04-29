#include <bits/stdc++.h>
using namespace std;

int solve()
{

    // N :số đơn vị lương thực nhiều nhất bạn có thể mua trong ngày.
    // S : số lượng ngày bạn cần được sử dụng lương thực để tồn tại.
    // M : số đơn vị lương thực cần có mỗi ngày để bạn tồn tại.

    int n, s, m;
    cin >> n >> s >> m;

    int lt = s * m;
    int days = s - s / 7; // Bỏ 2 ngày chủ nhật
    if (lt > days * n)
        return -1;
    for (int i = 1; i <= days; i++)
    {
        if (lt <= n * i)
            return i;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve();
    }
    return 0;
}
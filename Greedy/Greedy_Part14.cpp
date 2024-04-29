#include <bits/stdc++.h>
using namespace std;

// Cho hai số nguyên dương S và D, trong đó S là tổng các chữ số và D là số các chữ số của
// một số. Nhiệm vụ của bạn là tìm số nhỏ nhất thỏa mãn S và D? Ví dụ với S = 9, D = 2 ta
// có số nhỏ nhất thỏa mãn S và D là 18
// 2
// 9 2
// 20 3

int solve()
{
    int s, d;
    cin >> s >> d;
    if (s > d * 9)
        return -1;
    int res[d];
    --s;
    for (int i = d - 1; i > 0; i--)
    {
        if (s >= 9)
        {
            res[i] = 9;
            s -= 9;
        }
        else
        {
            res[i] = s;
            s = 0;
        }
    }
    res[0] = s + 1;
    for (auto x : res)
    {
        cout << x << " ";
    }
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
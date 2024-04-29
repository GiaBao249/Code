#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    // 4a + 7b = n
    for (int b = n / 7; b >= 0; b--)
    {
        int remain = n - 7 * b;
        if (remain % 4 == 0)
        {
            int a = remain / 4;
            cout << string(a, '4');
            cout << string(b, '7');
            return;
        }
    }
    cout << -1;
}
int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}
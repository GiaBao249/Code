#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
// Code đi đừng sợ!

void Solve()
{
    vector<int> a(3);
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    int i = 5;
    while (i--)
    {
        sort(a.begin(), a.end());
        a[0]++;
    }
    cout << a[0] * a[1] * a[2] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
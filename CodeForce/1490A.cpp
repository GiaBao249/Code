#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0;
    int x = a[0];
    for (int i = 1; i < n; i++)
    {
        int t = min(x, a[i]);
        int y = max(x, a[i]);
        while (2 * t < y)
        {
            cnt++;
            t *= 2;
        }
        x = a[i];
    }
    cout << cnt << endl;
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
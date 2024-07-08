#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m + 1);
    for (int i = 0; i < m + 1; i++)
        cin >> a[i];
    int com = a[a.size() - 1];
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        int c = com;
        c ^= a[i];
        int count = __builtin_popcount(c);
        if (count <= k)
            res++;
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
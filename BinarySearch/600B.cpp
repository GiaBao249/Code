#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define inf INT_MAX
#define maxn
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    f0(i, n)
    {
        cin >> a[i];
    }
    f0(i, m) cin >> b[i];
    vector<int> res;
    sort(all(a));
    f0(i, m)
    {
        auto it = upper_bound(all(a), b[i]);
        if (it != a.begin())
        {
            it--;
            int idx = distance(a.begin(), it);
            res.push_back(idx + 1);
        }
        else
        {
            res.push_back(0);
        }
    }
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    Solve();
    return 0;
}
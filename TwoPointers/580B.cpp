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

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

void Solve()
{
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> p(n);
    f0(i, n)
    {
        cin >> p[i].first;
        cin >> p[i].second;
    }
    sort(all(p));
    ll mx = -inf, sum = 0;
    int j = 0;
    f0(i, n)
    {
        sum += p[i].second;
        while (p[i].first - p[j].first >= d)
        {
            sum -= p[j].second;
            j++;
        }
        mx = max(mx, sum);
    }
    cout << mx << endl;
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
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}
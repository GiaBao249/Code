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
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    vector<int> pos;
    f0(i, n) if (s[i] == 'g') pos.push_back(i);

    int j = 0;
    int m = pos.size();
    int res = -inf;
    f0(i, n)
    {
        if (s[i] == c)
        {
            while (j < m && pos[j] < i)
                j++;
            if (j < m)
                res = max(res, pos[j] - i);
            else
                res = max(res, n - i + pos[0]);
        }
    }
    cout << res << endl;
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
    int t;
    cin >> t;
    while (t--)
        Solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}
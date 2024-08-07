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
    vector<int> posG;
    f0(i, n)
    {
        if (s[i] == 'g')
            posG.push_back(i);
    }
    int res = 0;
    f0(i, n)
    {
        if (s[i] == c)
        {
            auto it = lower_bound(all(posG), i);
            if (it != posG.end())
                res = max(res, *it - i);
            else
                res = max(res, n - i + posG[0]);
            cout << res << endl;
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
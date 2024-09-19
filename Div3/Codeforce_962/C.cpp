#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define MAXN
void Solve()
{
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    vector<vector<int>>
        preA(n + 1, vector<int>(26, 0)),
        preB(n + 1, vector<int>(26, 0));
    f0(i, 0, n)
    {
        f0(j, 0, 26)
        {
            preA[i + 1][j] = preA[i][j];
            preB[i + 1][j] = preB[i][j];
        }
        preA[i + 1][s[i] - 'a']++;
        preB[i + 1][t[i] - 'a']++;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        vector<int> a(26, 0), b(26, 0);
        f0(i, 0, 26)
        {
            a[i] = preA[r + 1][i] - preA[l][i];
            b[i] = preB[r + 1][i] - preB[l][i];
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            cnt += abs(a[i] - b[i]);
        }
        cout << cnt / 2 << endl;
    }
}
signed main()
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
    return 0;
}

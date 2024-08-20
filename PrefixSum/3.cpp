#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 200005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
int n, q;
vector<ll> dif, a, cnt;
void Solve()
{
    cin >> n >> q;
    dif.resize(n, 0);
    a.resize(n,0);
    f0(i,n) cin >> a[i];
    while(q--) {
        int l, r;
        cin >> l >> r;
        l-- , r--;
        dif[l]++;
        dif[r + 1]--;
    }
    vector<int> pre(n, 0);
    pre[0] = dif[0];
    for(int i = 1 ; i < n ; i++)
        pre[i] = pre[i - 1] + dif[i];
    sort(rall(pre));
    sort(rall(a));
    ll res = 0;
    for(int i = 0 ; i < n ; i++) {
        res += a[i] * pre[i];
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

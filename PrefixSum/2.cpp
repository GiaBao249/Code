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
vector<ll> dif, a;
void Solve()
{
    cin >> n >> q;
    dif.resize(n, 0);
    a.resize(n,0);
    f0(i,n) cin >> a[i];
    dif[0] = a[0];
    for(int i = 1 ; i < n ; i++) {
        dif[i] = a[i] - a[i - 1];
    }
    vector<int> pre(n);

    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        dif[l] += k;
        dif[r + 1] -= k;
    }
    pre[0] = dif[0];
    for(int i = 1 ; i < n ;i++)
        pre[i] = pre[i - 1] + dif[i];
    for(auto x : pre)
        cout << x << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

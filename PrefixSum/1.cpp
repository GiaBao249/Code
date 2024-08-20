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
int n, k, q;
vector<ll> pre;
vector<ll> cnt;
void Solve()
{
    cin >> n >> k >> q;
    pre.resize(maxn, 0);
    cnt.resize(maxn, 0);
    f1(i,n) {
        int u, v;
        cin >> u >> v;
        pre[u]++;
        pre[v + 1]--;
    }
    for(int i = 1 ; i <= maxn; i++) {
        pre[i] += pre[i - 1];
    }
    int c = 0;
    for(int i = 1 ; i <= maxn; i++) {
        if(pre[i] >= k)
            c++;
        cnt[i] = c;
    }
    f0(i, q) {
        int l, r;
        cin >> l >> r;
        cout << cnt[r] - cnt[l - 1] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

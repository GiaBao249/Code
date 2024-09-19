#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 2e5 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
int n, q;
ll a[maxn], t[4 * maxn];

void update(int id, int l, int r, int p, int v)
{
    if(p < l || p > r) return;
    if(l == r){ t[id] += v ; return;}
    int mid = (l + r) / 2;
    update(id * 2, l, mid, p, v);
    update(id * 2 + 1, mid + 1, r, p, v);
    t[id] = max(t[id * 2] , t[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v)
{
    if(u > r || v < l) return 0;
    if(l >= u && r <= v) return t[id];
    int mid = (l + r) >> 1;
    ll t1 = get(id * 2, l, mid, u, v);
    ll t2 = get(id * 2 + 1, mid + 1, r, u, v);
    return max(t1 ,t2);
}

int Bs(int id, int l, int r, int x) {
    if (t[id] < x) return 0;
    if (l == r) return l;
    int mid = (l + r) / 2;
    int res = Bs(id * 2, l, mid, x);
    if (res) return res;
    return Bs(id * 2 + 1, mid + 1, r, x);
}

void Solve()
{
    cin >> n >> q;
    f1(i,n) {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    f1(i, q) {
        int x;
        cin >> x;
        int idx = Bs(1 , 1 , n ,x);
        if(idx != 0) {
            cout << idx << " ";
            update(1, 1, n, idx, -x);
        } else {
            cout << 0 << " ";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        Solve();
    return 0;
}

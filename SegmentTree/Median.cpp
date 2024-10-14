#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)x.size()
#define el '\n'
const ll N = 2e5 + 10;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

ll t[N << 2], a[N];
int n, k;

void update(int id, int l, int r, int p, int v) {
    if (p < l || p > r) return;
    if (l == r) {
        t[id] += v;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, p, v);
    update(id << 1 | 1, mid + 1, r, p, v);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

ll get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) {
        return 0;
    }
    if (l >= u && r <= v) return t[id];
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

int bs(int id, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (t[id << 1] >= x) {
        return bs(id << 1, l, mid, x);
    } else {
        return bs(id << 1 | 1, mid + 1, r, x - t[id << 1]);
    }
}

void Solve() {
    cin >> n >> k;
    f1(i, n) cin >> a[i];
    vector<ll> v;
    f1(i, n) v.pb(a[i]);
    sort(all(v));
    f1(i, n) a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
    f1(i, k - 1) {
        update(1, 1, n, a[i], 1);
    }
    for (int i = k; i <= n; i++) {
        update(1, 1, n, a[i], 1);
        int mid = (k + 1) >> 1;
        int x = bs(1, 1, n, mid);
        cout << v[x - 1] << ' ';
        if(i - k >= 0)
            update(1, 1, n, a[i - k + 1], -1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}

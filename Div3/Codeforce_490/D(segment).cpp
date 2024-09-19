///Ever try ever failed no matter , try again fail again fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)x.size()
#define el '\n'
#define inf INT_MAX
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

ll t[4 * N], a[N];
vector<int> f(N);
int n, m, k;

void build(int id, int l, int r)
{
    if(l == r) {
        t[id] = (f[l] < k ? 1 : 0);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

void update(int id, int l, int r, int p, int v)
{
    if(p < l || p > r) {
        return;
    }
    if(l == r) {
        t[id] = v;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, p, v);
    update(id << 1 | 1, mid + 1, r, p, v);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

ll get(int id, int l, int r, int u, int v)
{
    if(l > v || r < u) {
        return 0;
    }
    if(l >= u && r <= v) {
        return t[id];
    }
    int mid = (l + r ) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

int bs(int x)
{
    int l = x % m + 1, r = m;
    int u = get(1, 1, m, l, r);
    if(u > 0) {
        while(l < r) {
            int mid = (l + r) / 2;
            if(get(1 , 1,  m, l , mid ) > 0){
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }else {
        l = 1 , r = x;
        while(l < r){
            int mid = (l + r) / 2;
            if(get(1 , 1, m , l, mid) > 0){
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
}

void Solve()
{
    cin >> n >> m;
    k = n / m;
    f1(i, n) {
        cin >> a[i];
        f[a[i] % m + 1]++;
    }
    build(1, 1, m);
    ll cnt = 0;
    f1(i, n) {
        int t = a[i] % m + 1;
        if(f[t] <= k)
            continue;
        int x = bs(t);
        int d = (x - t + m) % m;
        if(d < 0) d += m;
        a[i] += d;
        cnt += d;
        f[t]--;
        if(f[t] == k - 1)
            update(1 , 1, m, t , 1);
        f[x]++;
        if(f[x] == k){
            update(1 , 1, m, x , 0);
        }
    }
    cout << cnt << el;
    f1(i , n){
        cout << a[i] << ' ';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}


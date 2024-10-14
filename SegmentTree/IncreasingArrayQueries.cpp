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
#define MAX INT_MAX
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
struct Query{
    ll f , s;
};
ll n , q;
ll a[N] , day[N << 2] , pre[N << 2] , f[N << 2];
ll ans = 0;
void build(ll id , ll l , ll r){
    if(l == r){
        day[id] = a[l]; 
        //pre[l] = a[l];
        f[id] = 0;
        return;
    }
    ll mid = l + r >> 1;

    build(id << 1 , l , mid);
    build(id << 1 | 1 , mid + 1 , r);
    day[id] = a[l];
    f[id] = 0;
    pre[l] = a[l];
    for(ll i = l + 1 ; i <= r ; i++){
        if(a[i] >= day[id]){
            day[id] = a[i];
        }else{
            f[id] += (day[id] - a[i]); 
        }
        //pre[i] = pre[i - 1] + a[i];
    }
    //cout << id << ' ' << day[id] << ' ' << f[id] << el;
}

Query get(ll id, ll l, ll r, ll u, ll v, ll val) {
    if (l > v || r < u) {
        return {0, 0};
    }
    if (l >= u && r <= v) {
        if(l == r){
            if(a[l] < val)
                return {val , val - a[l]};
                else return {a[l] , 0};
            }
            ll mid = l + r >> 1;
            if(day[id] <= val){
                return {val , (val * (r - l + 1) - (pre[r] - pre[l - 1]))}; 
            }
            else if(day[id << 1] >= val){
                ll k = get(id << 1 , l , mid, u , v , val).s;
                return {day[id], k + (f[id] - f[id << 1])};
            }
        }
    ll mid = (l + r) >> 1;
    Query t1 = get(id << 1, l, mid, u, v, val);
    Query t2 = get(id << 1 | 1, mid + 1, r, u, v, t1.f);
    return {t2.f, t1.s + t2.s};
}


void Solve() {
    cin >> n >> q;
    f1(i , n) cin >> a[i];
    pre[0] = 0;
    f1(i , n) {
        pre[i] = pre[i - 1] + a[i];
    }
    build(1 , 1, n);
    //f1(i , n << 2) cout << day[i] << ' ';
    while(q--){
        ll l , r;
        cin >> l >> r;
        if(l == r){
            cout << 0 << el;
            continue;
        }
        cout << get(1 , 1, n , l , r , 0).s << el;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
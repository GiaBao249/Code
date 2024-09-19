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
ll t[N << 2] , a[N];
ll n , q;
void update(ll id , ll l , ll r , ll p , ll v){
    if(p < l || p > r)
        return;
    if(l == r){
        t[id] = v;
        return;
    }
    ll mid = (l + r) >> 1;
    update(id << 1 , l , mid , p , v);
    update(id << 1 | 1 , mid + 1,  r , p , v);
    t[id] = t[id << 1] + t[id << 1 | 1];
}
ll get(ll id , ll l , ll r , ll u , ll v){
    if(v < l || u > r){
        return 0;
    }
    if(l >= u && r <= v){
        return t[id];
    }
    ll mid = (l + r) >> 1;
    return get(id << 1 , l , mid , u , v) + get(id << 1 | 1  , mid + 1 , r , u , v);
}

ll f(ll x){
    ll u = x / n;
    ll v = x % n;
    ll res = get(1 , 1 , n , 1 , n) * u;
    if(v > 0){
        if(u + v <= n){
            res += get(1 , 1 , n , u + 1, u + v);
        }else{
            res += get(1 , 1 , n , u + 1 , n) + get(1 , 1 , n , 1 , u + v - n);
        }
    }
    return res;
}

void Solve()
{
    cin >> n >> q;
    f1(i , n){
        cin >> a[i];
        update(1 , 1 , n , i , a[i]);
    }
    while(q--){
        ll l , r;
        cin >> l >> r;
        cout << f(r) - f(l - 1) << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    ll t ; cin >> t;
    while(t--)
    Solve();
    return 0;
}


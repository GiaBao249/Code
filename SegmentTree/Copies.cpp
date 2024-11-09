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

struct Node{
    ll lo , hi , sum;
};

vector<Node> t(N << 5);
vector<ll> root;
ll a[N];
ll n , q , nextIndex = 1; 

ll build(ll l , ll r){
    ll cur = nextIndex++;
    if(l == r){
        t[cur].sum = a[l];
        return cur;
    }
    ll mid = (l + r) >> 1;
    t[cur].lo = build(l , mid);
    t[cur].hi = build(mid + 1 ,r);
    t[cur].sum = t[t[cur].lo].sum + t[t[cur].hi].sum;
    return cur;
}

ll update(ll prev , ll l , ll r , ll p , ll v){
    ll cur = nextIndex++;
    t[cur] = t[prev];
    if(l == r){
        t[cur].sum = v;
        return cur;
    }
    ll mid = (l + r) >> 1;
    if(p <= mid)t[cur].lo = update(t[prev].lo , l , mid , p , v);
    else t[cur].hi = update(t[prev].hi , mid + 1 , r , p , v);
    t[cur].sum = t[t[cur].lo].sum + t[t[cur].hi].sum;
    return cur;
}

ll get(ll root , ll l , ll r , ll u , ll v){
    if(l > v || r < u){
        return 0;
    }
    if(l >= u && r <= v){
        return t[root].sum;
    }   
    ll mid = (l + r) >> 1;
    return get(t[root].lo , l , mid , u , v) + get(t[root].hi , mid + 1 , r , u , v); 
}

void Solve() {
    cin >> n >> q;
    f0(i , n) cin >> a[i];
    root.pb(build(0 , n - 1));
    while(q--){
        ll t ; cin >> t;
        if(t == 1){
            ll k , a, x;
            cin >> k >> a >> x;
            k--, a--;
            root[k] = (update(root[k] , 0 , n - 1 , a , x));
        }else if(t == 2){
            ll k , a , b;
            cin >> k >> a >> b;
            k-- , a-- , b--;
            cout << get(root[k] , 0 , n - 1, a , b) << el;
        }else{
            ll k ; cin >> k;
            k--;
            root.pb(root[k]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
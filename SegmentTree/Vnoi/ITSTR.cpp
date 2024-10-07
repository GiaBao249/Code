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
const ll N = 1e5 + 10;
const ll MOD = 1007050321;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

struct Node{
    ll sum , cnt , w;
};
string s;
ll q;
Node t[N << 2]; 
ll p[N];
Node operator+(Node a , Node b){
    Node res;
    res.sum = ((a.sum * p[(b.cnt)]) % MOD + b.sum) % MOD;
    res.cnt = a.cnt + b.cnt;
    res.w = a.w + b.w;
    return res;
}

void build(ll id , ll l , ll r){
    if(l == r){
        t[id] = Node{s[l] - '0' , 1 , 1};
        return;
    }
    ll mid = l + r >> 1;
    build(id << 1 , l , mid);
    build(id << 1 | 1 , mid + 1 ,r);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

Node get(ll id , ll l , ll r , ll u , ll v){
    if(l > v || r < u){
        return {0 , 0 , 0};
    }
    if(l >= u && r <= v){
        return t[id];
    }
    ll mid = (l + r) >> 1;
    Node lo = get(id << 1 , l , mid , u , v);
    Node hi = get(id << 1 | 1, mid + 1 , r , u , v);
    return lo + hi;
}

ll bs(ll id , ll l , ll r , ll x){
    if(l == r){
        return l;
    }
    ll mid = (l + r ) >> 1;
    if(t[id << 1].w >= x){
        return bs(id << 1 , l , mid , x);
    }
    return bs(id << 1 | 1 , mid + 1, r , x - t[id << 1].w);
}

void update(ll id , ll l , ll r , ll p){
    if(p < l || p > r)
        return;
    if(l == r){
        t[id].cnt--;
        t[id].sum = t[id].w = 0;
        return;
    }
    ll mid = (l + r) >> 1;
    update(id << 1 , l , mid , p);
    update(id << 1 | 1, mid + 1 , r , p);
    t[id] = t[id << 1] + t[id << 1 | 1];
} 

void Solve() {
    cin >> s >> q;
    ll n = sz(s);
    s = ' ' + s;
    p[0] = 1;
	f1(i , n){
		p[i] = (p[i - 1] << 1) % MOD;
	}
    build(1 , 1, n);
    while(q--){
        char c; cin >> c;
        if(c == '-'){
            ll p ; cin >> p;
            ll x = bs(1 , 1, n , p);
            update(1 , 1, n , x);
        }
        else{
            ll l , r;
            cin >> l >> r;
            ll u = bs(1 , 1, n , l);
            ll v = bs(1 , 1, n , r);
            cout << get(1 , 1, n , u , v).sum << el;
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
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
const ll N = 2e5 + 10;
const ll mod = 1e3 + 7;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n , q; 
ll t[N << 2], lz[N << 2];

ll Mul(ll a , ll b){
    ll res = 0;
    a = a % mod;
    while(b){
        if(b & 1){
            res = (res + a) % mod;
        }
        a <<= 1;
        a %= mod;
        b >>= 1;
    } 
    return res;
}
struct matrix{
    ll X[2][2];
    friend matrix operator*(matrix a , matrix b){
        matrix c;
        f0(i , 2){
            f0(j , 2){
                c.X[i][j] = 0;
                f0(k , 2){
                    c.X[i][j] = (c.X[i][j] + (a.X[i][k] * b.X[k][j])) % mod;
                }
            }
        }
        return c;
    }   
};

matrix binPow(matrix a , ll n){
    if(n == 1){
        return a;
    }
    matrix x = binPow(a , n >> 1);
    x = x * x;
    if(n % 2 == 1)
        x = x * a;
    return x;
}

ll getFb(ll k){
    if(k <= 1){
        return k % mod;
    }
    matrix a ;
    a.X[0][0] = 1; 
    a.X[0][1] = 1; 
    a.X[1][0] = 1; 
    a.X[1][1] = 0;
    matrix ans = binPow(a , k - 1);
    return ans.X[0][0];
}

void push(ll id , ll l , ll r){
    if(lz[id]){
        t[id] += (lz[id] * (r - l + 1));
        if(l != r){
            lz[id << 1] += lz[id];
            lz[id << 1 | 1] += lz[id];
        }
        lz[id] = 0;
    }
}

void build(ll id , ll l , ll r){
    if(l == r){
        t[id] = 0;
        return;
    }
    ll mid = (l + r) >> 1;
    build(id << 1 , l , mid);
    build(id << 1 | 1 , mid + 1 , r);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

void update(ll id , ll l , ll r , ll u , ll v , ll p){
    push(id , l , r);
    if(l > v || r < u){
        return;
    }
    if(l >= u && r <= v){
        lz[id] += p;
        push(id , l , r);
        return;
    }
    ll mid = (l + r) >> 1;
    update(id << 1 , l , mid , u , v , p);
    update(id << 1 | 1 , mid + 1 , r , u , v , p);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

ll get(ll id , ll l , ll r , ll u , ll v){
    push(id , l ,r );
    if(l > v || r < u){
        return 0;
    }
    if(l >= u && r <= v){
        return t[id];
    }
    ll mid = l + r >> 1;
    return get(id << 1 , l , mid , u , v) + get(id << 1 | 1 , mid + 1 ,r , u , v);
}

void Solve() {
    cin >> n >> q;
    build(1 , 1 ,n);
    while(q--){
        ll t ; cin >> t;
        if(t == 1){
            ll l , r,  v;
            cin >> l >> r >> v;
            update(1 , 1 , n , l , r , getFb(v));
            //cout << getFb(v) << el;
        }
        else{
            ll l , r;
            cin >> l >> r;
            cout << get(1 , 1 ,n , l , r) << el;
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

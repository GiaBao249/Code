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
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n , q;
multiset<int> t[N << 2];
int a[N];
void build(int id , int l , int r){
    if(l == r){
        t[id].insert(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1 , l , mid);
    build(id << 1 | 1 , mid + 1 , r);
    t[id].insert(all(t[id << 1]));
    t[id].insert(all(t[id << 1 | 1]));
}

void update(int id , int l , int r ,int p , int u , int v){
    if(p < l || p > r) return;
    if(l == r){
        t[id].erase(t[id].find(u));
        t[id].insert(v);
        a[p] = v;
        return;
    }
    int mid = (l + r ) >> 1;
    update(id << 1 , l , mid , p ,u , v);
    update(id << 1 | 1 , mid + 1 , r , p , u, v);
    t[id].erase(t[id].find(u));
    t[id].insert(v);
}

int get(int id , int l , int r , int u , int v , int k){
    if(l > v || r < u){
        return inf;
    }
    if(l >= u && r <= v){
        auto x = t[id].lower_bound(k);
        if(x != t[id].end()){
            return *x;
        }
        return inf;
    }
    int mid = (l + r) >> 1;
    return min(get(id << 1 , l , mid , u , v , k) , get(id << 1 | 1 , mid + 1 , r , u , v ,k));
}

void Solve() {
    cin >> n >> q;
    f1(i , n) cin >> a[i];
    build(1 , 1, n);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int p , v;
            cin >> p >> v;
            update(1 , 1 , n , p , a[p], v);
        }else{
            int u , v, k;
            cin >> u >> v >> k;
            int x = get(1 , 1 , n , u , v , k);
            if(x == inf){
                cout << -1 << el;
            }else 
                cout << x << el;
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
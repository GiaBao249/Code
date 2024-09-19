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
const ll N = 4e5 + 5;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
struct Node{
    int i , l , r;
};

bool cmp(Node &a , Node &b){
    return a.r < b.r;
}
ll t[4 * N] , las[N] , n , q;
vector<Node> query;

void update(int id , int l , int r , int p , int v){
    if (p < l || p > r)
        return;
    if(l == r)
    {
        t[id] = v;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1 , l , mid , p , v);
    update(id << 1 | 1 , mid + 1 , r , p , v);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

int get(int id , int l , int r , int u , int v)
{
    if(l > v || r < u){
        return 0;
    }
    if(l >= u && r <= v){
        return t[id];
    }
    int mid = (l + r) >> 1;
    return get(id << 1  , l , mid , u , v) + get(id << 1 | 1 , mid + 1 , r , u , v);
}

void Solve()
{
    cin >> n >> q;
    vector<int> a(n + 1) , v;
    f1(i , n){
        cin >> a[i];
        v.pb(a[i]);
    }
    query.resize(q);
    sort(all(v));
    //v.erase(unique(all(v)) , v.end());

    f1(i , n){
        a[i] = lower_bound(all(v) , a[i]) - v.begin() + 1;
    }
    CLR(las , 0);
    f0(i , q){
        cin >> query[i].l >> query[i].r;
        query[i].i = i;
    }
    sort(all(query) , cmp);
    vector<int> res(q);
    int k = 0;
    int m = sz(v);
    f1(i , n){
        int v = a[i];
        if(las[v]){
            update(1 , 1 , n, las[v] , 0);
        }
        las[v] = i;
        update(1 , 1 , n , i , 1);
        while (k < q && query[k].r == i){
            res[query[k].i] = get(1 , 1 , n , query[k].l , query[k].r);
            k++;
        }
    }
    for(auto x : res){
        cout << x << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}


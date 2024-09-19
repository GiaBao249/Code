///Ever try ever failed no matter , try again fail again , fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf LONG_MAX
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
struct Node{
    int l , r , i;
    bool operator < (const Node &a) const
    {
        if(a.l == l)
            return a.r < r;
        return l < a.l;
    }
};

ll t[4 * N], n;
Node a[N], res[N];
void update(int id , int l , int r , int p)
{
    if(p < l || p > r)
        return;
    if(l == r)
    {
        t[id]++;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1 , l , mid , p);
    update(id << 1 | 1 , mid + 1, r , p);
    t[id] = (t[id << 1] + t[id << 1 | 1]);
}

ll get(int id , int l ,int r , int u , int v)
{
    if(l > v || r < u)
        return 0;
    if(l >= u && r <= v)
        return t[id];
    int mid = (l + r) >> 1;
    return get(id << 1 , l , mid , u , v) + get(id << 1 | 1  , mid + 1 , r , u , v);
}
unordered_map<int , int> mp;
set<int> se;
void Solve()
{
    cin >> n;
    f0(i , n){
        cin >> a[i].l >> a[i].r;
        a[i].i = i;
        se.insert(a[i].r);
    }
    int m = 1;
    for(auto x : se) mp[x] = m++;
    sort(a , a + n);
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        ll x = mp[a[i].r];
        res[a[i].i].r = get(1 , 1 , m , 1 , x);
        update(1 , 1 , m , x);
    }
    CLR(t , 0);
    f0(i ,n)
    {
        ll x = mp[a[i].r];
        res[a[i].i].l = get(1 , 1 , m , x , m);
        update(1 , 1 , m ,x);
    }
    f0(i , n) cout << res[i].r << " ";
    cout << el;
    f0(i , n) cout << res[i].l << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

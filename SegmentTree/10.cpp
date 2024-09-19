#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define CLR(a) memset((a),0,sizeof(a))
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)x.size()
#define el '\n'
#define inf INT_MAX
const ll N = 200005;
const ll MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/2206/
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
ll sp[4 * N] , ss[4 * N] , a[N] , n , q;
vector<ll> u(N) , v(N);
void update(ll id , ll l , ll r , ll p , ll v , ll tree[])
{
    if(p < l || p > r)
        return;
    if(l == r)
    {
        tree[id] = v;
        return;
    }
    ll mid = (l + r) / 2;
    update(id * 2 , l , mid , p , v , tree);
    update(id * 2 + 1 , mid + 1, r , p , v , tree);
    tree[id] = min(tree[id * 2] , tree[id * 2 + 1]);
}

ll get(ll id , ll l , ll r , ll u , ll v , ll tree[])
{
    if(u > r || l > v)
        return inf;
    if(u <= l && r <= v)
        return tree[id];
    ll mid = (l + r ) / 2;
    return min(get(id *2 , l , mid , u , v, tree) , get(id * 2 + 1, mid + 1,  r , u , v, tree));
}

void Solve()
{
    cin >> n >> q;
    f1(i , n) cin >> a[i];
    u.resize(n + 1, inf) , v.resize(n + 1, inf);
    f1(i , n)
    {
        u[i] = a[i] + i;
        v[i] = a[i] - i;
        update(1 , 1, n , i , u[i] , sp);
        update(1 , 1, n , i , v[i] , ss);
    }
    while(q--)
    {
        ll t ; cin >> t;
        if(t == 1)
        {
            ll p , v ;
            cin >> p >> v;
            update(1 , 1 , n , p , v + p, sp);
            update(1 , 1 , n , p , v - p, ss);
        }else
        {
            ll k; cin >> k;
            cout << min(get(1, 1, n, 1, k, ss) + k, get(1, 1, n, k, n, sp) - k) << el;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

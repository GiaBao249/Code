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
/ >  \> https://cses.fi/problemset/task/1190
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
struct Node{
    ll pre , suf , sum , mx;
};
Node operator + (const Node &a , const Node &b)
{
    Node res;
    res.pre = max(a.sum + b.pre , a.pre);
    res.suf = max(b.suf , a.suf + b.sum);
    res.sum = a.sum + b.sum;
    res.mx = max({a.mx , b.mx , a.suf + b.pre});
    return res;
}
Node t[4 * N];
ll a[N] , n , q;
void update(ll id , ll l , ll r , ll p , ll v)
{
    if(p < l || p > r)
        return;
    if(l == r)
    {
        t[id] = {v , v , v , v};
        return;
    }
    ll mid = (l + r) / 2;
    update(id * 2 , l , mid , p , v);
    update(id * 2 + 1 , mid + 1, r , p , v);
    t[id] = t[id * 2] + t[id * 2 + 1];
}

Node get(ll id , ll l , ll r , ll u , ll v)
{
    if(u > r || l > v)
        return {-inf , -inf , 0 , -inf};
    if(u <= l && r <= v)
        return t[id];
    ll mid = (l + r ) / 2;
    return get(id * 2 , l , mid , u , v) + get(id * 2 + 1 , mid + 1 , r , u , v);
}

void Solve()
{
    cin >> n >> q;
    f1(i , n){
        cin >> a[i];
        update(1 , 1 , n , i , a[i]);
    }
    while(q--)
    {
        int p , v;
        cin >> p >> v;
        update(1 , 1 , n , p , v);
        cout << max(0LL ,get(1 , 1 , n , 1 , n).mx) << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

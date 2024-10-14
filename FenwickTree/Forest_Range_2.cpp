#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int N = 1e4 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
 
ll bit[N][N];
char a[N][N];
void update(ll x, ll y, ll v)
{
    for(ll i = x; i < N ; i += i & -i) {
        for(ll j = y; j < N; j += j & -j) {
            bit[i][j] += v;
        }
    }
}
 
ll get(ll x, ll y)
{
    ll res = 0;
    for(ll i = x ; i > 0 ; i -= i & -i) {
        for(ll j = y ; j > 0 ; j -= j & -j) {
            res += bit[i][j];
        }
    }
    return res;
}
 
void Solve()
{
    ll n,q;
    cin >> n >> q;
    f1(i,n) {
        f1(j, n) {
            cin >> a[i][j];
            if(a[i][j] == '*')
                update(i, j, 1);
        }
    }
    while(q--) {
        ll t; cin >> t;
        if(t == 1){
            ll u , v;
            cin >> u >> v;
            if(a[u][v] == '.'){
                update(u , v , 1);
                a[u][v] = '*';
            }
            else{
                update(u , v, -1);
                a[u][v] = '.';
            }
        }else{
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2 ;
            cout << get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1) << el;
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
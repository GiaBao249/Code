///Ever try ever failed no matter , try again fail again , fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll ,ll>;
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
const int N = 200005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n, q;
ll a[N], t[4 * N];

void update(int id, int l, int r, int p, int v)
{
    if(p < l || p > r) return;
    if(l == r){ t[id] += v ; return;}
    int mid = (l + r) / 2;
    update(id * 2, l, mid, p, v);
    update(id * 2 + 1, mid + 1, r, p, v);
    t[id] = max(t[id * 2] , t[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v)
{
    if(u > r || v < l) return 0;
    if(l >= u && r <= v) return t[id];
    int mid = (l + r) >> 1;
    ll t1 = get(id * 2, l, mid, u, v);
    ll t2 = get(id * 2 + 1, mid + 1, r, u, v);
    return max(t1 ,t2);
}

int bs(int id , int l , int r , int x)
{
    if(t[id] < x) return 0;
    if(l == r)
        return l;
    int mid = (l + r) / 2;
    int res = 0;
    res = bs(id * 2 , l , mid , x);
    if(res != 0)
        return res;
    return bs(id * 2 + 1 , mid + 1 , r , x);
}

void Solve()
{
    cin >> n >> q;
    f1(i , n){
        cin >> a[i];
        update(1 , 1 , n , i , a[i]);
    }
    f1(i , q)
    {
        int x ; cin >> x;
        int idx = bs(1 , 1 , n , x);
        if(idx == 0)
            cout << 0 << " ";
        else{
            cout << idx << " ";
            update(1 , 1, n , idx,-x);
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

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
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
ll n , k;
ll a[N] , b[N];
pii get(ll lb){
    ll op = 0 , s = 0;
    f0(i , n){
        ll d = max(a[i] - lb , 0LL);
        ll f = (d / b[i]) + (a[i] >= lb);
        op += f;
        s += (f * a[i] - (f * (f - 1) / 2) * b[i]);
    }
    if(op > k){
        s -= (op - k) * lb;
    }
    return {op , s};
}
void Solve()
{
    cin >> n >> k;
    f0(i , n) cin >> a[i];
    f0(i , n) cin >> b[i];
    ll l = 0 , r = inf;
    while(r - l > 1){
        ll mid = (l + r) >> 1;
        if(get(mid).first >= k){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << get(l).second << el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    ll t ;
    cin >> t;
    while(t--)
        Solve();
    time;
    return 0;
}


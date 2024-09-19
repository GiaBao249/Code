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
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
void Solve()
{
    int n , m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> f(m,0);
    int k = n / m;
    f0(i , n){
        cin >> a[i];
        f[a[i] % m]++;
    }
    set<int> se;
    f0(i , m){
        if(f[i] < k){
            se.insert(i);
        }
    }
    for(auto x : se){
        cout << x << ' ';
    }
    cout << el;
    ll cnt = 0;
    f0(i , n){
        int t = a[i] % m;
        if(f[t] <= k){
            continue;
        }
        auto it = se.upper_bound(t);
        if(it == se.end()){
            it = se.begin();
        }
        int d = *it - t;
        if(d < 0){
            d += m;
        }
        cnt += d;
        a[i] += d;
        --f[t];
        if(++f[*it] >= k)
            se.erase(*it);
    }
    cout << cnt << el;
    for(auto x : a){
        cout << x << ' ';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}



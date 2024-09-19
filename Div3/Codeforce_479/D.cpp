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
const ll N = 105;
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
    int n;
    cin >> n;
    vector<ll> a(n), res;
    f0(i, n) cin >> a[i];

    unordered_set<ll> se(all(a));
    for(auto x : a) {
        vector<ll> v;
        v.pb(x);
        se.erase(x);
        while(true) {
            ll b = v.back();
            auto u = se.find(b / 3);
            auto it = se.find(b * 2);
            if(u != se.end() && b % 3 == 0) {
                v.pb(b / 3);
                se.erase(b / 3);
            } else if(it != se.end()) {
                v.pb(b * 2);
                se.erase(b * 2);
            } else {
                break;
            }
        }
        if(sz(v) == n) {
            f0(i, n) cout << v[i] << ' ';
            return;
        }
        for(auto x : v)
            se.insert(x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}



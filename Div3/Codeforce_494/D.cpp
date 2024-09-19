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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int ,int> mp;
    f0(i, n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    while(q--) {
        int u ;
        cin >> u;
        int ans = 0;
        for(int i = 30 ; i >= 0 && u > 0 ; i--){
            int d = (1 << i);
            if(mp[d] > 0){
                int t = min(mp[d] , u / d);
                ans += t;
                u -= d * t;
            }
        }
        if(u == 0)
            cout << ans << el;
        else
            cout << -1 << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}


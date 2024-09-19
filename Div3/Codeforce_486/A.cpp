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
const ll N = 0;
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n) , vis(105 , 0) , res;
    f0(i, n) {
        cin >> a[i];
        if(!vis[a[i]]) {
            res.pb(i + 1);
            vis[a[i]] = 1;
        }
    }
    if(res.size() < k) {
        cout << "NO" << el;
    } else {
        cout << "YES" << el;
        for(int i = 0 ; i < k; i++) {
            cout << res[i] << ' ';
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


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

bool cmp(pii &a, pii &b)
{
    return a.first < b.first;
}
void Solve()
{
    int n, q;
    cin >> n >> q;
    vector<pii> a(n);
    vector<ll> v;
    f0(i, n) {
        cin >> a[i].first;
        a[i].second = i;
        v.pb(a[i].first);
    }
    sort(all(v));
    vector<int> res(n, 0);
    f0(i, n) {
        auto u = lower_bound(all(v), a[i].first) - v.begin();
        res[a[i].second] = u;
    }
    f0(i , q){
        int x , y;
        cin >> x >> y;
        --x , --y;
        if(a[x].first > a[y].first)
            res[x]--;
        else if(a[x].first < a[y].first)
            res[y]--;
    }
    f0(i, n) {
        if(res[i] < 0){
            cout << 0 << ' ';
        }else
            cout << res[i] << ' ';
    }
    cout << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}


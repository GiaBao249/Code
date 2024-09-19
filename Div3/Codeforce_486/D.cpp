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
#define inf I_MAX
const ll N = 0;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
ll n ;
vector<ll> a;
void Solve()
{
    cin >> n;
    a.resize(n);
    f0(i, n) cin >> a[i];
    sort(all(a));
    for(ll i = 30 ; i >= 0 ; i--) {
        ll x = (1 << i);
        for(ll j = 0 ; j < n ; j++) {
            if(binary_search(all(a), a[j] - x) && binary_search(all(a), a[j] + x)) {
                cout << 3 << el;
                cout << a[j] << ' ' << a[j] + x << ' ' << a[j] - x << el;
                return;
            }
        }
    }
    for(ll i = 30 ; i >= 0 ; i--) {
        ll x = (1 << i);
        for(ll j = 0 ; j < n ; j++) {
            if(binary_search(all(a), a[j] - x)) {
                cout << 2 << el;
                cout << a[j] << ' ' << a[j] - x << el;
                return;
            }
        }
    }

    for(ll i = 30 ; i >= 0 ; i--) {
        ll x = (1 << i);
        for(ll j = 0 ; j < n ; j++) {
            if(binary_search(all(a), a[j] + x)) {
                cout << 2 << el;
                cout << a[j] << ' ' << a[j] + x << el;
                return;
            }
        }
    }
    cout << 1 << el << a[rand() % n] << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}


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
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;
vector<int> st ;
vector<bool> is_st;

vector<ll> Div(ll n) {
    vector<ll> div;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            div.pb(i);
            if(i * i != n) {
                div.pb(n / i);
            }
        }
    }
    sort(all(div));
    return div;
}

void Solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    
    vector<ll> DivC = Div(c);
    ll ans = -1;
    for(ll x : DivC) {
        if(x % a == 0 && x % b != 0 && d % x != 0) {
            if(ans == -1 || x < ans) {
                ans = x;
            }
        }
    }
    
    cout << ans << el;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //file();
    Solve();
    return 0;
}
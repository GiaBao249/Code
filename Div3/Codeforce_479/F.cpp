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
#define inf LLONG_MAX
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;
//https://codeforces.com/contest/977/problem/F
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
void Solve()
{
    int n; cin >> n;
    vector<int> a(n) , dp(n) , par;
    f0(i , n) cin >> a[i];
    unordered_map<int , int> mp;
    ll mx = -1;
    ll rs = 0;
    for(int i = 0 ; i < n; i++){
        if(mp.count(a[i] - 1)){
            dp[i] = mp[a[i] - 1] + 1;
            mp[a[i]] = dp[i];
        }
        else{
            dp[i] = 1;
            mp[a[i]] = 1;
        }
    }
    f0(i , n){
        if(dp[i] > mx){
            mx = dp[i];
            rs = i;
        }
    }
    int p = a[rs];
    par.pb(rs + 1);
    for(int i = rs ; i >= 0 ; i--){
        if(a[i] == p - 1){
            par.pb(i + 1);
            p = a[i];
        }
    }
    reverse(all(par));
    cout << mx << el;
    for(auto x : par) cout << x << ' ';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}


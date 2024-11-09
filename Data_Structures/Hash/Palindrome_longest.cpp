//Ever try ever failed no matter , try again fail again fail better!
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
#define MAX ll_MAX
const ll N = 5e4 + 5;
const ll MOD = 1000000003;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

const ll base = 31;
ll p[N] , Hash[N], HashRev[N];
string s;
ll n;

ll getHash(ll i , ll j){
    return (Hash[j] - Hash[i - 1] * p[j - i + 1] + MOD * MOD) % MOD;
}

ll getHashRev(ll i , ll j){
    return (HashRev[j] - HashRev[i - 1] * p[j - i + 1] + MOD * MOD) % MOD;
}
bool var(ll mid){
    for(ll i = 1 ; i + mid - 1 <= n ; i++){
        ll j = n - (i + mid - 1) + 1;
        if(j < 1 || j + mid - 1 > n) continue;
        if(getHash(i , i + mid - 1) == getHashRev(j, j + mid - 1)){ 
            return true;
        }
    }
    return false;
}


void Solve() {
    cin >> n >> s;
    p[0] = 1;
    string t = s;
    reverse(all(t));
    s = ' ' + s;
    t = ' ' + t;
    Hash[0] = HashRev[0] = 0;
    f1(i , n){
        p[i] = (p[i - 1] * base) % MOD; 
    }
    f1(i , n){
        Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1) % MOD;
    }
    f1(i , n){
        HashRev[i] = (HashRev[i - 1] * base + t[i] - 'a' + 1) % MOD;
    }
    ll l = 1 , r = n;
    ll ans = 0;
    while(l <= r){
        ll mid = l + r >> 1;
        if(var(2 * mid)){
            ans = max(ans , 2 * mid);
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    l = 1 , r = n;
    while(l <= r){
        ll mid = l + r >> 1;
        if(var(2 * mid + 1)){
            ans = max(ans ,  2 * mid + 1);
            l = mid + 1;
        }   else{
            r = mid - 1;
        }
    }
    cout << ans << el;
}  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
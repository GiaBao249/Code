///Ever try ever failed no matter , try again fail again fail better!
// Quy hoạch động giúp ta nhìn thấy sự ngu dốt chứ k phải giúp chúng ta nhìn solution
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)x.size()
#define el '\n'
#define MAX INT_MAX
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
ll f[N] , a[N];
void Solve() {
    int n , k; cin >> n >> k;
    f1(i , n) cin >> a[i];
    f1(i , n) f[i] = inf;
    f[1] = 0;
    for(int i = 2 ; i <= n; i++){
        for(int j = i; j > 0 && (i - j <= k) ; j--){
            f[i] = min(f[i] ,abs(a[j] - a[i]) + f[j]);
        }
    }
    cout << f[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}

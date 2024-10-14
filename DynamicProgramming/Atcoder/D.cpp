///Ever try ever failed no matter , try again fail again fail better!
// Quy hoạch động giúp ta nhìn thấy sự ngu dốt chứ k phải giúp chúng ta nhìn solution
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
#define MAX INT_MAX
const ll N = 105;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
ll dp[100005];
vector<pii> a(N);
void Solve() {
    int n , x;
    cin >> n >> x;
    f1(i , n) cin >> a[i].first >> a[i].second;
    f1(i , n){
        for(int j = x ; j >= a[i].first ; j--){
            dp[j] = max(dp[j - a[i].first] + a[i].second ,dp[j]);
        }
    }
    cout << dp[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
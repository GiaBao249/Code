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
const ll N = 1e6 + 6;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n, x;
bool check(int a, int b, int c)
{
    return a + b + c <= x && a*b + b*c + a*c <= n;
}
void Solve()
{
    cin >> n >> x;
    ll cnt = 0;
    for(int a = 1 ; a <= x ; a++) {
        for (int b = 1; b <= min(n / a, x - a); b++) {
            int l = 0, r = min(x - a - b , (n - a * b) / (a + b));
            int c = 0;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(mid <= min(x - a - b, (n - a * b) / (a + b))) {
                    if(check(a , b , c)){
                        c = mid;
                    }
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            cnt += max(0 , c);
        }
    }
    cout << cnt << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin >> t;
    while(t--)
        Solve();
    return 0;
}



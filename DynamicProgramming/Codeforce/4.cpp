///Ever try ever failed no matter , try again fail again , fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf LONG_MAX
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

int cv(string &s) {
    int mask = 0;
    if (s.find('A') != string::npos) mask |= 1;
    if (s.find('B') != string::npos) mask |= 2;
    if (s.find('C') != string::npos) mask |= 4;
    return mask;
}
int n ;
void Solve()
{
    cin >> n;
    ll dp[n + 1][8];
    f0(i, n) f0(j, 8) dp[i][j] = inf;
    dp[0][0] = 0;
    int mask = 0;
    f0(i, n) {
        int c ;
        string s;
        cin >> c >> s;
        mask = cv(s);
        f0(j, 8) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j | mask] = min(dp[i + 1][j | mask],dp[i][j] + c);
        }
    }
    if(dp[n][7] == inf)
        cout << -1 << el;
    else
        cout << dp[n][7] << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}


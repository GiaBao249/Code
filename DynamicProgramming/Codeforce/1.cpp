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
#define inf LLONG_MAX
const int N = 200005;
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
ll n ;
vector<ll> dp(N);
int cal(int i)
{
    ll res = 0;
    while(i > 0)
    {
        res += i % 10;
        i /= 10;
    }
    return res;
}
void run()
{
    for(int i = 1 ; i < N ; i++)
    {
        dp[i] = dp[i - 1] + cal(i);
    }
}
void Solve()
{
    cin >> n;
    cout << dp[n] << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}

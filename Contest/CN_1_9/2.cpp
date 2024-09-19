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
const int N = 10000;
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
int n , x;
vector<int> a , b;
void Solve()
{
    cin >> n >> x;
    vector<vector<int>> dp(n + 1, vector<int>(N + 1, 0));
    dp[0][0] = 1;
    f0(i , n)
    {
        int u , v ;
        cin >> u >> v;
        a.pb(u);
        b.pb(v);
    }
    f1(i , n)
    {
        for(int j = 0 ; j <= N ; j++)
        {
            if(dp[i - 1][j])
            {
                if(j + a[i - 1] <= N)
                    dp[i][j + a[i - 1]] = 1;
                if(j + b[i - 1] <= N)
                    dp[i][j + b[i - 1]] = 1;
            }
        }
    }
    if(dp[n][x])
        cout << "Yes" << el;
    else
        cout << "No" << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

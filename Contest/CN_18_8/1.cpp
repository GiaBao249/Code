#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 2e5 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>http://upcoder.xyz/'index.php/ca451ba38a89daba11c4071c2f9ae511cf7c260ea46637d19f68ce622850c271/mtzS?%27%27zpNReNt$x64%27moNe5@qlR%27pxRfoLqs%27vviBnt%27686C%272k7d.8he~CdL7_5iK887?0PM9g5N2N_54/3b0280368149b7e6c42fcd4675876616a149c00ab3c53c8029824952eff419cf
*/
vector<vector<ll>> dp;
void Solve()
{
    string s , t;
    cin >> s >> t;
    dp.resize(2,vector<ll>(2 * sz(s) , 0));
    int n = sz(s);
    if(s[0] == 'X')
        dp[0][0] = 1;
    if(t[0] == 'X')
        dp[1][0] = 1;
    for(int i = 1 ; i < n ; i++)
    {
        if(s[i] == 'X')
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
        if(t[i] == 'X')
            dp[1][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
    }
    cout << ((dp[0][n - 1] + dp[1][n - 1]) % MOD) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

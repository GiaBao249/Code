#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 0;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1745/
*/

set<int> se;
int n, s = 0;
bool dp[200005];
void Solve()
{
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    memset(dp, false, sizeof(dp));
    f0(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    dp[0] = true;
    For(i, 0, n) {
        for(int j = sum ; j >= 0 ; j--){
            if(dp[j])
            {
                dp[j + a[i]] = true;
                se.insert(j + a[i]);
            }
        }
    }
    cout << sz(se) << el;
    for(auto x : se)
        cout << x << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

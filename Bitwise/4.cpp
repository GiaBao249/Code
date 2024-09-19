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
/ >  \> https://codeforces.com/contest/1420/problem/B
*/
void Solve()
{
    int n ;
    cin >> n;
    vector<int> a(n);
    f0(i, n) cin >> a[i];
    ll ans = 0;
    vector<ll> cnt(32, 0);
    for(auto x : a) {
        for(int i = 29 ; i >= 0 ; i--) {
            if(x & (1LL << i)){
                cnt[i]++;
                break;
            }
        }
    }
    for(auto x : cnt)
        ans += (1LL * x * (x - 1) / 2);
    cout << ans << el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}

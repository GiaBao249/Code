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
const int maxn = 300005;
const int MOD = 1e9 + 7;

void Solve()
{
    int n , s;
    cin >> n >> s;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;
    int l = 0 , res = 0;
    multiset<int> se;
    for(int r = 0; r < n ; r++)
    {
        se.insert(a[r]);
        while(!se.empty() && (*se.rbegin() - *se.begin()) > s){
            se.erase(a[l]);
            l++;
        }
        res += r - l + 1;
    }
    cout << res << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

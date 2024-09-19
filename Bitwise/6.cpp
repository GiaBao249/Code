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
/ >  \>
*/
vector<int> a, cnt(32, 0), d;
unordered_map<int, int> mp;
void Solve()
{
    int t;
    cin >> t;
    int sz = 0;
    for(int i = 0 ; i < t ; i++) {
        int n;
        cin >> n;
        ll ans = 0;
        if(n == 1) {
            int x ;
            cin >> x;
            sz++;
            mp[x]++;
            f0(i, 32) {
                if(x & (1 << i)) {
                    cnt[i]++;
                }
            }
        } else if(n == 2) {
            int x ;
            cin >> x;
            if(mp[x] > 0) {
                sz--;
                mp[x]--;
                if (mp[x] == 0) {
                    mp.erase(x);
                }
                f0(i, 32) {
                    if(x & (1 << i))
                        cnt[i]--;
                }
            }
        } else if(n == 3) {
            if(sz == 0) {
                cout << 0 << el;
                continue;
            }
            f0(i, 32) {
                if(cnt[i] > 0) {
                    ans += (1 << i);
                }
            }
            cout << ans << el;
        } else if(n == 4) {
            if(sz == 0) {
                cout << 0 << el;
                continue;
            }
            f0(i, 32) {

                if(cnt[i] == sz) {
                    ans += (1LL << i);
                }
            }
            cout << ans << el;
        } else if(n == 5) {
            if(sz == 0) {
                cout << 0 << el;
                continue;
            }
            f0(i, 32) {
                if(cnt[i] & 1) {
                    ans += (1 << i);
                }
            }
            cout << ans << el;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

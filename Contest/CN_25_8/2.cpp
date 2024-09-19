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
const int maxn = 2e5 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
int n, k;
struct Node {
    ll s, e;
};
vector<Node> a;
bool cmp(Node &a, Node &b)
{
    if(a.s == b.s)
        return a.e < b.e;
    return a.s < b.s;
}
void Solve()
{
    cin >> n >> k;
    a.resize(n);
    f0(i, n) cin >> a[i].s >> a[i].e;
    ll cnt = 0;
    multiset<int> se;
    sort(all(a),cmp);
    f0(i, n) {
        if(sz(se) < k) {
            se.insert(a[i].e);
            cnt++;
        } else {
            auto u = se.upper_bound(a[i].s);
            if(se.begin() != u) {
                u--;
                se.erase(u);
                se.insert(a[i].e);
                cnt++;
            }
            while(!se.empty() && *se.begin() <= a[i].s)
                se.erase(se.begin());
        }
    }
    cout << cnt << el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

//Ever try ever failed no matter , try again fail again fail better!
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
#define MAX INT_MAX
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

int n , q , a[N];
void Solve() {
    cin >> n >> q;
    f1(i , n) cin >> a[i];
    set<ll> se(a + 1 , a + n + 1);
    // gom sao cho tối ưu nhất mà không quá 2 bãi rác 
    // bản chất : tìm khoảng cách giữa 2 điểm sao đường đi từ 2 đỉnh là nhỏ nhất
    // chặt nhị phân trên set?
    // Lưu từng kc lớn nhất vào và xử lí trong multiset (mệt vl)
    // 1 2 6 8 10
    // b1  |1 2| + |6 8 10| = 5
    // b2 +4 -> |1 2 4| + |6 8 10| = 7
    // b3 +9 -> |1 2 4| + |6 8 9 10| => 3 + 4 = 7 
    // b4 -6 -> |1 2 4| + |8 9 10| => 3 + 2 = 5
    // b5 -10 -> |1 2 4| + |8 9| => 4
    multiset<ll> kc;
    if(sz(se) > 2){
        int l = -1 , r = -1;
        ll mx = -inf;
        for(auto s : se){
            auto u = se.upper_bound(s);
            if(u == se.end()){
                continue;
            }
            if(abs(s - *u) > mx){
                l = s;
                r = *u;
                mx = abs(s - *u);
            }
        }
        cout << l - *se.begin() + *se.rbegin() - r << el;
    }else{
        cout << 0 << el;
    }
    auto u = se.begin();
    auto v = u;
    u++;
    while (u != se.end()){
        kc.insert(*u - *v);
        v = u;
        u++;
    }
    //for(auto x : kc) cout << x << ' ';
    while(q--){
        int t  ; cin >> t;
        if(t == 0){
            int x ; cin >> x;
            auto cur = se.find(x);
            if(cur == se.end()) continue;
            if(sz(se) > 1){
                if(cur != se.begin()){
                    auto pv = prev(cur);
                    if(kc.find(*cur - *pv) != kc.end())
                        kc.erase(kc.find(*cur - *pv));
                    if(cur != se.end()){
                        auto nx = next(cur);
                        if(nx != se.end()){
                            if(kc.find(*nx - *cur) != kc.end())
                                kc.erase(kc.find(*nx - *cur));
                            kc.insert(*nx - *pv);
                        }
                    }
                }else if(next(cur) != se.end()){
                    if(kc.find(*next(cur) - *cur) != kc.end())
                        kc.erase(kc.find(*next(cur) - *cur));
                }
            }
            se.erase(cur);
        }else{
            ll x ; cin >> x;
            se.insert(x);
            auto cur = se.find(x);
            if(sz(se) > 1){
                if(cur != se.begin()){
                    auto pv = prev(cur);
                    if(next(cur) != se.end()){
                        if(kc.find(*next(cur) - *pv) != kc.end())
                            kc.erase(kc.find(*next(cur) - *pv));
                    }
                    kc.insert(*cur - *pv);
                }
                if(next(cur) != se.end()){
                    kc.insert(*next(cur) - *cur);
                }
            }
        }
        if(sz(se) > 2)
            cout << (*se.rbegin() - *se.begin()) - *kc.rbegin() << el;
        else cout << 0 << el;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
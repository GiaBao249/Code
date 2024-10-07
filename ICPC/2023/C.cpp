///Ever try ever failed no matter , try again fail again fail better!
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
#define inf INT_MAX
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

struct P3{
    int x , y , z;
    bool operator<(const P3& other) const {
        return tie(x, y, z) < tie(other.x, other.y, other.z);
    }
};

struct P2{
    int x , y;
    bool operator<(const P2 & other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};
int n , q;
void Solve() {
    cin >> n >> q;
    set<P3> x0 , y0 , z0;
    while(q--){
        int x , y , z;
        cin >> x >> y >> z;
        if(x == 0) x0.insert({x , y , z});
        else if(y == 0) y0.insert({x , y , z});
        else if(z == 0) z0.insert({x , y , z});
    }
    map<int , int> xx , yy , zz;
    map<P2,int> xy;
    ll ans = 0;
    for(auto i : x0){
        ans += n;
        yy[i.y]++, zz[i.z]++;
    }
    for(auto i : y0){
        ans += n - zz[i.z];  
        xx[i.x]++;
        for(auto j : x0){
            if(i.z == j.z){
                xy[{i.x , j.y}]++;
            }
        }
    }
    for(auto i : z0){
        ans += n - xx[i.x] - yy[i.y] + xy[{i.x , i.y}];
    }
    cout << ans << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
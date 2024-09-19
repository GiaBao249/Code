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
const ll N = 0;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
void Solve()
{
    int k; cin >> k;
    vector<vector<int>> sq(k);
    vector<int> sum(k);
    f0(i , k)
    {
        int n;  cin >> n;
        int s = 0;
        sq[i].resize(n);
        f0(j, n){
            cin >> sq[i][j];
            s += sq[i][j];
        }
        sum[i] = s;
    }
    unordered_map<int, pair<int, int>> mp;
    for(int i = 0 ;  i < k ; i++){
        for(int j = 0;  j < sq[i].size() ;j++){
            int t  = sum[i] - sq[i][j];
            if(mp.count(t) && mp[t].first != i){
                auto [u , v] = mp[t];
                cout << "YES" << el;
                cout << u + 1 << ' ' << v + 1 << el;
                cout << i + 1 << ' ' << j + 1  << el;
                return;
            }else{
                mp[t] = {i , j};
            }
        }
    }
    cout << "NO" << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}


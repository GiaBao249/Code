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
const ll N = 200005;
const ll MOD = 1e9 + 7;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int , null_type , less<int> ,
rb_tree_tag ,tree_order_statistics_node_update>indxed_set;


void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
void Solve()
{
    int n , k ;
    cin >> n >> k;
    indxed_set s;
    f1(i , n){
        s.insert(i);
    }
    int pos = 0;
    for(int i = n ; i >= 1; i--){
        pos = (pos + k) % i;
        auto x = s.find_by_order(pos);
        cout << *x << ' ';
        s.erase(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}


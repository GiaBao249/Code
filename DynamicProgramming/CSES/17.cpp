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
const ll N = 11;
const ll M = 1001;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
// biểu diễn bằng trạng thái bit với cách đánh dấu 1 khi ô đã được tô
ll dp[M][1 << N];
int n , m;
void dfs(int i , int id , int cur , int next){
    if(id == n){
        // tổng số cách từ cách chọn ô trước và cách chọn ô sau
        dp[i + 1][next] = (dp[i + 1][next] + dp[i][cur]) % MOD;
        return;
    }
    // nếu ô đang xét đã được đánh dấu thì chạy tiếp
    if(cur & (1 << id)){
        dfs(i , id + 1, cur , next);
    }else{
        // đánh dấu ô ngang 1x2
        dfs(i , id + 1 , cur , next | (1 << id));
        // đánh dấu ô dọc 2x1
        if(id + 1 < n && !(cur & (1 << (id + 1)))){
            dfs(i , id + 2 , cur , next);
        }
    }
}
void Solve() {
    cin >> n >> m;
    dp[0][0] = 1;
    f0(i , m){
        for(int mask = 0 ; mask < (1 << n) ; mask++){
            if(dp[i][mask]){
                dfs(i , 0 , mask , 0);
            }
        }
    }
    cout << dp[m][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
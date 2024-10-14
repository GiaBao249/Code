#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e2 + 5;
const ll MOD = 1e9 + 7;

ll n, k, dp[N][N], a[N];

void Solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    // Khởi tạo
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            // Không chọn phần tử thứ i
            dp[i][j] = dp[i-1][j];
            dp[i][j] += dp[i][j - 1];
            // Chọn phần tử thứ i nếu có thể
            if(j >= a[i]) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]]) % MOD;
            }
        }
    }
    
    cout << dp[n][k] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
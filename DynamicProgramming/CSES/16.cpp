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
const ll N = 21;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

int n , k;
ll a[N];
vector<pii> dp(1 << N , pii({inf , inf}));
void Solve() {
    cin >> n >> k;
    f1(i , n) cin >> a[i];
    dp[0] = {1 , 0}; // đối với tập hợp 0 thì luôn có 1 cách để đi đc thang máy first là slot , second là weight
    //Duyệt qua tất cả các tập con có thể xác định
    for(int mask = 1 ; mask < (1 << n) ; mask++){
        f1(i , n){
            //check điểm i tại phần tử mask xem có đc bật lên hay không
            if((1 << (i - 1)) & mask){
                // dp[mask ^ (1 << (i - 1))].second -> chuyển trạng thái thành prev để kiểm tra
                int empty = dp[(mask ^ (1 << (i - 1)))].second; // kiểm tra chỗ ở phía bên phải ô bit cuối cùng có thể chứa đc thêm người nào nữa không -> còn chỗ chứa phần tử tiếp theo
                if(empty + a[i] <= k){
                    // Nếu còn đủ chỗ thì đáp ứng đc và chỉ cần tăng số w hiện tại lên
                    dp[mask] = min(dp[mask] , {dp[mask ^ (1 << (i - 1))].first , empty + a[i]});
                }else{
                    // Nếu không còn đủ chỗ thì không đáp ứng đc và chỉ cần giữ nguyên w hiện tại và tăng slot còn trống lên 1
                    dp[mask] = min(dp[mask] , {dp[mask ^ (1 << (i - 1))].first + 1 ,a[i]});
                }
            }
        }
    }
    // kết quả là số slot có thể đạt đc
    cout << dp[(1 << n) - 1].first << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
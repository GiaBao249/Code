///Ever try ever failed no matter , try again fail again , fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
using vi = vector<int>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf LONG_MAX
const int N = 0;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://codeforces.com/problemset/problem/1355/B
*/
/// Bước 1 : Sort lại các phần tử sao cho vị trí các người có chỉ số kinh nghiệm(a[i]) tăng dần -> dễ quản lí
/// Bước 2 : Với n người thì tối đa sẽ tạo đc n nhóm -> dp[i] = dp[i - 1] + 1 -> phân nhóm với từng số i
/// Bước 3 : Nếu điểm số kinh nghiệm của 1 người thỏa mãn điều kiện nhóm (a[i] <= dp[i + 1]) thì sẽ đc gom lại thành 1 nhóm
/// Bước 4 : đếm và đánh dấu xem nhóm nào đã đủ tiêu chí thì loại nhóm đó ra
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n;
vector<int> a, dp;


void Solve()
{
    cin >> n ;
    a.resize(n, 0);
    dp.resize(n + 1, 0);
    f0(i, n) cin >> a[i];
    sort(all(a));

    int cnt = 0;
    f0(i, n) {
        dp[i + 1] = dp[i] + 1;
        if(dp[i + 1] >= a[i]) {
            cnt++;
            dp[i + 1] = 0;
        }
    }
    cout << cnt << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}


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
const ll N = 50005;
const ll MOD = 1e9 + 7;

void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n;
int a[N] ,lo[N] ,hi[N];
bool check(int mid){
    // for(int i = mid ; i <= n - mid + 1 ; i++){
    //     bool b = true;
    //     if(a[i]<mid) continue;
    //     for(int j = 1 ; j < mid; j++){
    //         if(i-j<=0||i+j>n){
    //             b = false;
    //             break;
    //         }
    //         if(!(a[i - j] >= mid-j && a[i + j] >= mid - j)){
    //             b = false;
    //         }
    //     }
    //     if(b){return true;}
    // }
    // return false;
    for(int i = mid ; i <= n - mid + 1 ; i++){
        if(a[i] < mid)
            continue;
        if(lo[i - 1] >= mid - 1 && hi[i + 1] >= mid - 1){
            return true;
        }
    }
    return false;
}

void Solve() {
    cin >> n;
    a[0] = -inf;
    a[n + 1] = -inf;
    f1(i , n) cin >> a[i];
    //f1(i , n) cout << a[i] << ' ';
    int c = 0;
    for(int i = 1  ; i <= n ; i++){
        c = min(a[i] , c + 1);
        lo[i] = c;
    }
    c = 0;
    for(int i = n ; i > 0 ; i--){
        c = min(a[i] , c + 1);
        hi[i] = c;
    }
    int l = 1 , r = N;
    int res = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        //cout<<l<<" "<<r<<el;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    //cout<<check(7)<<el;
    cout << res << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    file();
    Solve();
    return 0;
}
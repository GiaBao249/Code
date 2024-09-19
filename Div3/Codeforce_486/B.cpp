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

bool cmp(string a , string b){
    return sz(a) < sz(b);
}
void Solve()
{
    int n ;
    cin >> n;
    vector<string> a(n);
    f0(i, n) {
        cin >> a[i];
    }
    sort(all(a) ,cmp);

    f1(i, n - 1) {
        if(a[i].find(a[i - 1]) == string :: npos) {
            cout << "NO" << el;
            return;
        }
    }
    cout << "YES" << el;
    f0(i, n) {
        cout << a[i] << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}


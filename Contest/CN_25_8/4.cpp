#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define CLR(a) memset((a),0,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int N = 0;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

ll cal(ll n)
{
    int cnt = 0;
    while(n % 2 == 0) {
        n /= 2;
        cnt++;
    }
    while(n % 3 == 0) {
        n /= 3;
        cnt++;
    }
    while(n % 5 == 0) {
        n /= 5;
        cnt++;
    }
    if(n == 1)
        return cnt;
    return -1;
}
void Solve()
{
    ll a, b;
    cin >> a >> b;
    if(a == b) {
        cout << 0 << el;
        return;
    }
    ll gcd = __gcd(a, b);
    a /= gcd;
    b /= gcd;
    ll x = cal(a);
    ll y = cal(b);
    if(x == -1 || y == -1)
        cout << -1 << el;
    else
        cout << x + y << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

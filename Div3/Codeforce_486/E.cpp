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
string s;
int check(char a, char b, int n)
{
    string t = s;
    int res = inf;
    int cnt = 0, p = -1 ;
    for(int i = n - 1; i >= 0 ; i--) {
        if(t[i] == b) {
            p = i;
            break;
        }
    }
    if(p == -1) return inf;
    for(int i = p ; i < n - 1 ; i++) {
        swap(t[i], t[i + 1]);
        cnt++;
    }
    p = -1;
    for(int i = n - 2 ; i >= 0 ; i--) {
        if(t[i] == a) {
            p = i;
            break;
        }
    }

    if(p == -1) return inf;
    for(int i = p ; i < n - 2 ; i++) {
        swap(t[i], t[i + 1]);
        cnt++;
    }
    if(t[0] != '0') {
        res = min(res, cnt);
        return res;
    }
    p = -1;
    for(int i = 0 ; i < n ; i++) {
        if(t[i] != '0') {
            p = i;
            break;
        }
    }
    while(p > 0) {
        swap(t[p], t[p - 1]);
        p--;
        cnt++;
    }
    if(t[n - 1] == b && t[n - 2] == a) {
        res = min(res, cnt);
        return res;
    }else {
        return inf;
    }
}

void Solve()
{
    cin >> s;
    int res = inf;
    int n = sz(s);
    res = min(res, check('0', '0', n));
    //cout << check('0', '0', n) << el;
    res = min(res,check('5', '0', n));
    //cout << check('5', '0', n) << el;
    res = min(res,check('2', '5', n));
    //cout << check('2', '5', n) << el;
    res = min(res,check('7', '5', n));
    //cout << check('7', '5', n) << el;
    if(res == inf) {
        cout << -1 << el;
    } else {
        cout << res << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}


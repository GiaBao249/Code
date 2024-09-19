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
const ll N = 2e5 + 5;
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
    int a, b, x;
    cin >> a >> b >> x;
    string s;
    for(int i = 0 ; i <= x; i++) {
        if(a > b){
            s += char('0' + (i & 1));
        }else{
            s += char('0' + (i + 1 & 1));
        }
    }
    for(char c : s){
        if(c == '0')
            a--;
        else
            b--;
    }
    for(char c : s){
        cout << c;
        if(c == '0'){
            while(a){
                cout << c;
                a--;
            }
        }
        else{
            while(b){
                cout << c;
                b--;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}



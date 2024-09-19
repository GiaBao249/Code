#include <bits/stdc++.h>
#define ll long long
using namespace std;
using vl = vector<ll>;
#define pb push_back
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 505;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://codeforces.com/contest/1517/problem/C
*/
int n;
vector<vl> a(maxn, vl(maxn, 0));
int cnt = 0;
void dfs(int i, int j, int x)
{
    if(x < cnt) {
        return;
    }
    a[i][j] = x;
    if(j - 1 > 0 && a[i][j - 1] == 0) {
        cnt++;
        dfs(i, j - 1,x);
    }
    if(i + 1 <= n && a[i + 1][j] == 0) {
        cnt++;
        dfs(i + 1, j, x);
    }
}

void Solve()
{
    cin >> n;
    f1(i,n) {
        int x;
        cin >> x;
        cnt = 1 ;
        dfs(i, i, x);
    }
    f1(i, n) {
        f1(j, i) {
            cout << a[i][j] << " ";
        }
        cout << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

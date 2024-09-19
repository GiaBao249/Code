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
const int maxn = 2e5 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1090
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
int n, w;
vl a(maxn);
void Solve()
{
    cin >> n >> w;
    a.resize(n + 1);
    f1(i, n) {
        cin >> a[i];
    }
    int cnt = 0 ;
    sort(all(a));
    int i = 1 , j = n;
    while(i <= j){
        if(a[i] + a[j] <= w){
            i++;
            j--;
        }
        else
            j--;
        cnt++;
    }
    cout << cnt << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

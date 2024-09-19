#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 1e4 + 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/

ll bit[maxn][maxn];

void update(int x, int y, int v)
{
    for(int i = x; i < maxn ; i += i & -i) {
        for(int j = y; j < maxn; j += j & -j) {
            bit[i][j] += v;
        }
    }
}

int get(int x, int y)
{
    int res = 0;
    for(int i = x ; i > 0 ; i -= i & -i) {
        for(int j = y ; j > 0 ; j -= j & -j) {
            res += bit[i][j];
        }
    }
    return res;
}

void Solve()
{
    int n,q;
    cin >> n >> q;
    f1(i,n) {
        f1(j, n) {
            char c ;
            cin >> c;
            if(c == '*')
                update(i, j, 1);
        }
    }
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2 ;
        cout << get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1) << el;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

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
const int maxn = 0;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
void Solve()
{
    int n, m;
    cin >> n >> m;
    int k = 0;
    if(n == 0 && m == 0) {
        cout << 1 << el;
        return;
    }
    if(n == 1)
    {
        cout << 2 << el;
        return;
    }
    if(n > m) {
        cout << 0 << el;
        return;
    } else if(n < m) {
        for(int i = 32 ; i >= 0 ; i--) {
            if((n & (1 << i)) != (m & (1 << i))) {
                k = i;
                break;
            }
        }
        cout << (1 << k) << el;
    }
    else{
        int x = 0;
        for(int i = 0 ; i < 32 ; i++)
        {
            if(n & (1 << i))
            {
                x += (1 << i);
                if(x == n)
                {
                    cout << (1 << (i + 1)) << el;
                    return;
                }
            }
            else
            {
                //n |= (1 << i);
                cout << (1 << i) << el;
                return;
            }
        }
    }
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

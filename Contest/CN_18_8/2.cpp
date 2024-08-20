#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 0;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> http://upcoder.xyz/'index.php/f8baa54183e759902439859e048e4d0fc0a1bb01ef318656d398481f6bcca86a/ixvr:''vTeTdPu_306'BpeNz$pnS'TtTbqMnw'xukojx'8786'iA?b.6-~986k68gK:fi85NK81?.38e.98/af54cec5460fe6160027a54fa89d0baa5a0caca20dd9a0681ef5c5e667109cc2
*/

ll get(int n)
{
    ll res = 0, p = 2;
    ll c = 1;
    while(p <= n) {
        res += ((n / p) - (n / (p * 2))) * c;
        p <<= 1;
        c++;
    }
    return res;
}

void Solve()
{
    ll a, b ;
    cin >> a >>b;
    cout << get(b) - get(a - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

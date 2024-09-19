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
const int maxn = 200005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> http://upcoder.xyz/'index.php/7c373c35240bd519286d6b8eb4a529d268b0324d36702a0a762b43afcd01531d/lvypJ''yRMoOMs!z5z'lBML4.skq'RwokBKpu's0hnmv'3__-'CkcP-eLAh4F8-i--a-K4:5@2!CgjgO8F'CUf9/14cb5c8495efde0c76187f6d2240f507eda1fa4902eda3eb8af8411e320cbf47
*/
void Solve()
{
    int n ;
    cin >> n;
    vector<int> a(n);
    f0(i, n) cin >> a[i];
    int res = 0, mask = 0;
    for(int i = 31 ; i >= 0 ; i--) {
        int bit = mask | (1 << i) , cnt = 0; // bit -> bật bit thứ i lên 1 -> có giá trị bằng 2^i
        for(auto x : a) {
            if((x & bit) == bit) {
                cnt++;
            }
        }
        if(cnt > 1)
        {
            mask = bit;
            res = mask;
        }
    }
    cout << res << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}

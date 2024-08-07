#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define inf INT_MAX
#define maxn
// http://upcoder.xyz/'index.php/d593a98cacee884d142b21108b707dd5ef26b3badfd42fb6dec1b51b23343262/ixvr:''vTeTdPu_306'BpeNz$pnS'TtTbqMnw'xukojx'86!5'-Lkd-5d9bM3~C2:hh7FhA.7k9Nf5LC@91/a694080f0a3894396f33be4215a61d452bd1ddd9e2d5a2c6b54ef2b9db150134
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    int cnt = 0, j = 0;
    f0(i, n)
    {
        cin >> a[i];
        mp[a[i]]++;
        while (mp.size() > k)
        {
            if (mp[a[j]] == 1)
                mp.erase(a[j]);
            else
                mp[a[j]]--;
            j++;
        }
        cnt += (i - j + 1);
    }
    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    Solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}
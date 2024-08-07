#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define inf INT_MAX

// http://upcoder.xyz/'index.php/42b7c78544c9b3dc9584d3c15c0b000153f081b215e4324f9517c8ab9107dd2d/nwuTF''0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'74-0'95EL7bF_e8L?0P.--e@dPf6iK-4!L-_66/12b5771a109b5ca0e3a40bdb75581032f677246ba9c61be7b4de1c7927379438

void Solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    f0(i, n) cin >> a[i];

    vector<ll> pre(n), suf(n), full(n + 1, 0);

    int q;
    cin >> q;

    pre[0] = a[0];
    suf[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
        pre[i] = max(pre[i - 1] + a[i], a[i]);

    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1] + a[i], a[i]);

    for (int i = 1; i <= n; i++)
        full[i] = full[i - 1] + a[i - 1];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        cout << pre[l] + pre[r] + (full[r] - full[l + 1]) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // if (fopen("input.txt", "r"))
    // {
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // }
    Solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Bs(int a[], int l, int r, int x, int &res)
{
    if (l > r)
        return;
    int mid = l + (r - l) / 2;
    if (a[mid] == x)
    {
        res = mid;
        Bs(a, l, mid - 1, x, res);
    }
    else if (a[mid] > x)
        Bs(a, l, mid - 1, x, res);
    else
        Bs(a, mid + 1, r, x, res);
}

ll mod(ll a, ll b, ll c)
{
    if (b == 0)
        return 0;
    ll t = mod(a, b >> 1, c);
    if (b & 1)
        return ((t << 1) + a % c) % c;
    else
        return (t << 1) % c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a[n];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = -1;
    Bs(a, 0, n - 1, 2, res);
    cout << res << endl;
}
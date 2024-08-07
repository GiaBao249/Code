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

// http://upcoder.xyz/'index.php/ad3f4f117345c1a8c621aa09d2486dedcf852f04faf8489af03a6ddac54181f7/lvypJ''yRMoOMs!z5z'lBML4.skq'RwokBKpu's0hnmv'2!66'9~7~7-~A91N_8Nhk1F566eN3kf-g6?c~9/83266356ed87d5e6ed757be422c2abc86c63fa620721a1c8932fb59a0d89d26d

void Solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    f0(i, n) cin >> a[i];

    ll mx = -inf;
    deque<ll> dq;

    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front() < i - k)
            dq.pop_front();

        if (!dq.empty())
            mx = max(mx, a[dq.front()] - a[i]);

        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();

        dq.push_back(i);
    }
    cout << mx << endl;
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
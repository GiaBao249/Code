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

int n;

struct FwTree
{
    vector<ll> bit;
    FwTree(int n) { bit.resize(21, 0); }

    void update(int i, int v)
    {
        for (; i < bit.size(); i += i & -i)
            bit[i] += v;
    }

    ll get(int i)
    {
        ll res = 0;
        for (; i >= 1; i &= i - 1)
            res += bit[i];
        return res;
    }
    void print()
    {
        for (int i = 1; i <= 20; i++)
        {
            cout << bit[i] << " ";
        }
        cout << endl;
    }
};

void Solve()
{
    cin >> n;
    vector<int> x(n), v(n);
    f0(i, n) cin >> x[i];
    f0(i, n) cin >> v[i];

    vector<int> vs = v;
    sort(all(vs));
    vs.erase(unique(all(vs)), vs.end());

    map<int, int> mp;
    f0(i, vs.size()) mp[vs[i]] = i + 1;

    vector<pair<int, int>> p;
    f0(i, n) p.emplace_back(x[i], mp[v[i]]);
    sort(all(p));

    FwTree fw1(vs.size());
    FwTree fw2(vs.size());
    ll res = 0;
    for (auto &[a, b] : p)
    {
        ll c = fw1.get(b);
        ll s = fw2.get(b);
        res += a * c - s;

        cout << "a: " << a << " c: " << c << " s: " << s << endl;
        cout << "res = " << res << endl;
        cout << "Before" << endl;
        fw1.print();
        fw2.print();

        fw1.update(b, 1);
        fw2.update(b, a);

        cout << "After" << endl;
        fw1.print();
        fw2.print();
    }
    cout << res << endl;
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
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define el '\n'

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(ALL(a), cmp);
    for (auto x : a)
    {
        auto t = mp.upper_bound(x.second);
        if (t != mp.begin())
        {
            --t;
            mp.erase(t);
            mp[x.second]++;
        }
        else
        {
            mp[x.second] = 1;
        }
    }
    cout << mp.size() << el;
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define el '\n'

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(ALL(a), cmp);

    for (auto x : a)
    {
        auto it = upper_bound(res.begin(), res.end(), x.second);
        if (it != res.begin())
        {
            --it;
            *it = x.second;
        }
        else
        {
            res.insert(res.begin(), x.second);
        }
        for (auto x : res)
            cout << x << " ";
        cout << endl;
    }
    // cout << res.size() << el;
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
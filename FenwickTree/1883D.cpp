#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 4e5 + 5;
/*
 /\_/\
(= >_<)
/ >  \> https://codeforces.com/contest/1883/problem/D
*/
struct st
{
    char c;
    int l, r;
};

vector<int> bit1(maxn, 0), bit2(maxn, 0);

// update giá trị từ i cho đến maxn
void update1(int i, int val)
{
    for (; i < maxn; i += i & -i)
        bit1[i] += val;
}

// update giá trị từ đầu cho đến i
void update2(int i, int val)
{
    for (; i > 0; i -= i & -i)
        bit2[i] += val;
}

// trả về giá trị từ đầu cho đến i
int get1(int i)
{
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += bit1[i];
    return res;
}

// trả về giá trị từ i cho đến maxn
int get2(int i)
{
    int res = 0;
    for (; i < maxn; i += i & -i)
        res += bit2[i];
    return res;
}

int compress(vector<int> &v, int x)
{
    return lower_bound(all(v), x) - v.begin() + 1;
}

vector<st> a;
int n;

void Solve()
{
    cin >> n;
    a.resize(n + 1);

    vector<int> v;

    f1(i, n)
    {
        cin >> a[i].c >> a[i].l >> a[i].r;
        v.push_back(a[i].l);
        v.push_back(a[i].r);
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());

    f1(i, n)
    {
        a[i].l = compress(v, a[i].l);
        a[i].r = compress(v, a[i].r);
    }

    int check = 0;

    f1(i, n)
    {
        auto x = a[i];
        int y = (x.c == '-') ? -1 : 1;

        update1(x.r, y);
        update2(x.l, y);

        check += y * get1(x.l - 1);
        check += y * get2(x.r + 1);

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
    Solve();
    return 0;
}
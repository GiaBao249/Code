#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define CLR(a) memset((a),0,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int N = 200005;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \> https://cses.fi/problemset/task/1734/
*/
void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
struct Node {
    ll i, l, r;
};
ll bit[N], n, q, a[N] , las[N];
vector<Node> qr;
vector<int> v;
void update(int i, int v)
{
    for(; i <= n ; i += i & -i) {
        bit[i] += v;
    }
}

ll get(int i)
{
    ll res = 0;
    for(; i > 0 ; i -= i & -i)
        res += bit[i];
    return res;
}

bool cmp(const Node &a, const Node &b) {
    return a.r < b.r;
}
void Solve()
{
    cin >> n >> q;
    f1(i, n){
         cin >> a[i];
         v.pb(a[i]);
    }

    qr.resize(q);
    CLR(las);
    f0(i, q) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].i = i;
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    f1(i , n) a[i] = lower_bound(all(v) , a[i]) - v.begin() + 1;
    sort(all(qr) , cmp);
    vector<int> res(q);
    int k = 0;
    cout << "A :";
    f1(i , n)
        cout << a[i] << " ";
    cout << el;
    f1 (i, n) {
        int v = a[i];
        if(las[v])
            update(las[v], -1);
        las[v] = i;
        update(i, 1);

        while(k < q && qr[k].r == i){
            res[qr[k].i] = get(qr[k].r) - get(qr[k].l - 1);
            k++;
        }
    }
    f0(i, q) cout << res[i] << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ///freopen("input.txt", "r", stdin);
    Solve();
    return 0;
}

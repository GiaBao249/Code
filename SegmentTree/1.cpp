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
const int maxn = 0;
/*
 /\_/\
(= >_<)
/ >  \>
*/
const int MAXN = 255;

struct Node
{
    ll sum, max_val;
    Node(ll s = 0, ll m = 0) : sum(s), max_val(m) {}
};

Node tree[4 * MAXN];
int arr[MAXN];

Node combine(Node left, Node right)
{
    return Node(left.sum + right.sum, max(left.max_val, right.max_val));
}

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = Node(arr[start], arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

Node query(int node, int start, int end, int l, int r)
{
    if (r < start || end < l)
        return Node();
    if (l <= start && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    Node left = query(2 * node, start, mid, l, r);
    Node right = query(2 * node + 1, mid + 1, end, l, r);
    return combine(left, right);
}

void Solve()
{
    int n;
    cin >> n;

    ll result = 0;
    for (int mid = 0; mid <= n; mid++)
    {
        for (int i = 1; i <= mid; i++)
        {
            arr[i] = i * i;
        }
        for (int i = mid + 1, j = n; i <= n; i++, j--)
        {
            arr[i] = i * j;
        }

        build(1, 1, n);

        Node total = query(1, 1, n, 1, n);
        result = max(result, total.sum - total.max_val);
    }

    cout << result << endl;
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
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
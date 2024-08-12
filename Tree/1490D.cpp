#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define inf INT_MAX
#define maxn 101
/*
 /\_/\
(= ._.)
/ >  \> https://codeforces.com/contest/1490/problem/D
*/
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
vector<int> a(maxn);

Node *BuildTree(vector<int> &a, int l, int r)
{
    if (l > r)
        return NULL;
    int mx = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (a[i] > a[mx])
            mx = i;
    }
    Node *tree = new Node(a[mx]);
    tree->left = BuildTree(a, l, mx - 1);
    tree->right = BuildTree(a, mx + 1, r);
    return tree;
}

int Dfs(Node *tree, int k, int d = 0)
{
    if (tree == NULL)
        return -1;
    if (tree->data == k)
        return d;

    int l = Dfs(tree->left, k, d + 1);
    if (l != -1)
        return l;
    return Dfs(tree->right, k, d + 1);
}

void Solve()
{
    int n;
    cin >> n;
    a.resize(n);
    vector<int> d;
    f0(i, n) cin >> a[i];
    Node *tree = BuildTree(a, 0, n - 1);
    f0(i, n) cout << Dfs(tree, a[i]) << " ";
    cout << endl;
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
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
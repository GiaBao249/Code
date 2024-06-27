#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <limits>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    unordered_map<int, int> head, tail;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (!head.count(a[i]))
            head[a[i]] = i + 1;
        tail[a[i]] = i + 1;
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        if (head[l] && tail[r] && head[l] < tail[r])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
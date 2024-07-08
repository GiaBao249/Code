#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    unordered_set<int> se;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
        if (se.find(a[i]) == se.end())
        {
            se.insert(a[i]);
            res.push_back(a[i]);
        }
    }
    cout << res.size() << endl;
    reverse(res.begin(), res.end());
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
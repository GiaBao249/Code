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
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "rated" << endl;
            return;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            cout << "unrated" << endl;
            return;
        }
    }
    cout << "maybe" << endl;
}
int main()
{
    Solve();
    return 0;
}
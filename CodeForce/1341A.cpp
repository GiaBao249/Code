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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int x = n * (a - b);
    int y = n * (a + b);
    if (y < c - d || x > c + d)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
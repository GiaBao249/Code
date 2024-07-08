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
#include <math.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    ll a, n;
    cin >> a >> n;
    ll d;
    if (n % 4 == 0)
        d = 0;
    else if (n % 4 == 1)
        d = n;
    else if (n % 4 == 2)
        d = -1;
    else
        d = -n - 1;
    if (a % 2 == 0)
        cout << a - d << endl;
    else
        cout << a + d << endl;
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
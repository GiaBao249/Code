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
    int a, b, c;
    cin >> a >> b >> c;
    int v[3] = {a, b, c};
    sort(v, v + 3);
    a = v[0];
    b = v[1];
    c = v[2];
    if (a == b && b == c)
    {
        cout << "YES" << endl;
        return;
    }
    if (b % a == 0 && c % a == 0 && (b / a - 1) + (c / a - 1) <= 3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
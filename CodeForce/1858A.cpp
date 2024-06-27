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
    ll a, b, c;
    cin >> a >> b >> c;
    if (a + c < b + c)
        cout << "Second" << endl;
    else if (a + c > b + c)
        cout << "First" << endl;
    else if (a == b && c % 2 == 1)
        cout << "First" << endl;
    else if (a == b && c % 2 == 0)
        cout << "Second" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
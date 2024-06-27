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
    int a, b;
    cin >> a >> b;
    if (b == 0)
    {
        cout << a + 1 << endl;
    }
    else if (a == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << a + (b * 2) + 1 << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
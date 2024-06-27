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
    if (a == b)
        cout << 0 << endl;
    else
    {
        if (a < b)
        {
            int x = b - a;
            if (x % 2 == 1)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
        else
        {
            int x = a - b;
            if (x % 2 == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
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
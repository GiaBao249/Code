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
    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b + c) % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    int res = 0;
    if (a + b <= c)
    {
        while (c != 0 && (a != 0 || b != 0))
        {
            res++;
            c--;
            if (a > 0)
                a--;
            else if (b > 0)
                b--;
        }
    }
    else
    {
        int x = a + b;
        while (x != c)
        {
            res++;
            x -= 2;
        }
        res += c;
    }
    cout << res << endl;
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
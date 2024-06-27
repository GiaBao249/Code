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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Solve()
{
    int n;
    cin >> n;
    int a = 0, b = 0, c = 1;
    for (int i = 2; i < n; i++)
    {
        int x = n - i - 1;
        if (gcd(x, i) == 1)
        {
            a = i;
            b = x;
            break;
        }
    }
    cout << a << " " << b << " " << c << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
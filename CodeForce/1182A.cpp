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

int test(ll n)
{
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
            return i;
    }
    return n;
}

void Solve()
{
    ll n, k;
    cin >> n >> k;
    n += test(n);
    k--;
    n += 2 * k;
    cout << n << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
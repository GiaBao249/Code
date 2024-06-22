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
#include <math.h>
using namespace std;
#define ll long long

void Solve()
{
    ll n;
    cin >> n;
    ll s = (n * (n + 1)) / 2;
    ll x = 1;
    while (x <= n)
    {
        s -= x * 2;
        x *= 2;
    }
    cout << s << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
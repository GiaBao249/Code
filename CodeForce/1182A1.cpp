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
    ll n;
    cin >> n;
    ll s = 1;
    if (n % 2)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        for (ll i = 0; i < n / 2; i++)
        {
            s *= 2;
        }
    }
    cout << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
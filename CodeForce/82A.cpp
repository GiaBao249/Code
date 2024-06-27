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
    int n;
    cin >> n;
    int i = 0;
    while (n > 5 * pow(2, i))
    {
        ll x = pow(2, i) * 5;
        n -= x;
        i++;
    }
    n--;
    int res = n / pow(2, i);
    if (res == 0)
        cout << "Sheldon";
    else if (res == 1)
        cout << "Leonard";
    else if (res == 2)
        cout << "Penny";
    else if (res == 3)
        cout << "Rajesh";
    else if (res == 4)
        cout << "Howard";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
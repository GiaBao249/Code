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
    int cnt = 0;
    ll p = 1;
    while (p <= n)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (j * p <= n)
                cnt++;
        }
        p = p * 10 + 1;
    }
    cout << cnt << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
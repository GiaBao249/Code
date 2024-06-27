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
    int n, m;
    cin >> n >> m;
    int temp = m;
    int cnt = 0;
    int i = 0;
    if (m % n != 0)
    {
        cout << -1 << endl;
        return;
    }
    int x = m / n;
    while (x % 2 == 0)
    {
        x /= 2;
        cnt++;
    }
    while (x % 3 == 0)
    {
        x /= 3;
        cnt++;
    }
    if (x != 1)
        cout << -1 << endl;
    else
        cout << cnt << endl;
}
int main()
{
    Solve();
    return 0;
}
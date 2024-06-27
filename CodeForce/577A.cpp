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
    int n, x;
    cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x % i == 0 && x / i <= n)
            cnt++;
    }
    cout << cnt << endl;
}
int main()
{
    Solve();
    return 0;
}
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
    int n;
    cin >> n;
    if (n % 3 == 0)
        cout << n / 3 << " " << (n / 3) + 1 << " " << (n / 3) - 1 << endl;
    else if (n % 3 == 1)
        cout << (n - 1) / 3 << " " << ((n - 1) / 3) + 2 << " " << ((n - 1) / 3) - 1 << endl;
    else if (n % 3 == 2)
        cout << ((n - 2) / 3) + 1 << " " << ((n - 2) / 3) + 2 << " " << (n - 2) / 3 - 1 << endl;
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
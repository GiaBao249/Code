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

void Solve()
{
    int n, m;
    cin >> n >> m;
    int s = 0;
    while (n > 0)
    {
        s++;
        n--;
        if (s % m == 0)
        {
            n++;
        }
    }
    cout << s << endl;
}
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    Solve();
    return 0;
}
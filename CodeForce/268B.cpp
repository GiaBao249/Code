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
    int s = 0;
    for (int i = 1; i < n; i++)
    {
        s += (n - i) * i;
    }
    s += n;
    cout << s << endl;
}
int main()
{
    Solve();
    return 0;
}
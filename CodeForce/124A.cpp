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
    int n, a, b;
    cin >> n >> a >> b;
    cout << n - max(a + 1, n - b) + 1 << endl;
}
int main()
{
    Solve();
    return 0;
}
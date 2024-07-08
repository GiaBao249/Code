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
    int a, b, c;
    cin >> a >> b >> c;
    int x = sqrt(a * b / c);
    int y = sqrt(a * c / b);
    int z = sqrt(b * c / a);
    cout << 4 * (x + y + z) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ll s1 = max((3 * a) / 10, a - a / 250 * c);
    ll s2 = max((3 * b) / 10, b - b / 250 * d);
    if (s1 > s2)
        cout << "Misha" << endl;
    else if (s1 < s2)
        cout << "Vasya" << endl;
    else
        cout << "Tie" << endl;
}
int main()
{
    Solve();
    return 0;
}
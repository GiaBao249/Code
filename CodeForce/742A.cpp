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
    if (n == 0)
        cout << 1 << endl;
    else if (n % 4 == 0)
        cout << 6 << endl;
    else if (n % 4 == 1)
        cout << 8 << endl;
    else if (n % 4 == 2)
        cout << 4 << endl;
    else if (n % 4 == 3)
        cout << 2 << endl;
    else
        cout << 0 << endl;
}
int main()
{
    Solve();
    return 0;
}
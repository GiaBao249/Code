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
#include <deque>
#include <numeric>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;
#define ll long long

void Solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (m * a <= b)
        cout << n * a << endl;
    else
        cout << (n / m) * b + min((n % m) * a, b) << endl;
}
int main()
{
    Solve();
    return 0;
}
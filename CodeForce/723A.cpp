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

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    int m = v[1];
    int res = 0;
    if (m == a)
        res += abs(a - c) + abs(a - b);
    else if (m == b)
        res += abs(b - c) + abs(b - a);
    else
        res += abs(a - c) + abs(c - b);
    cout << res << endl;
    return 0;
}
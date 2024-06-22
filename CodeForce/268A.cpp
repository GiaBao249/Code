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
    int t;
    cin >> t;
    vector<pair<int, int>> v;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    int cnt = 0;
    for (auto [a, b] : v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (a == v[i].second)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
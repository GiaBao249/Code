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
    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x <= 10)
            {
                v.push_back({i, y});
            }
        }
        int maxx = -1;
        for (auto [a, b] : v)
        {
            if (b > maxx)
            {
                maxx = b;
            }
        }
        for (auto [a, b] : v)
            if (b == maxx)
                cout << a + 1 << endl;
    }
    return 0;
}
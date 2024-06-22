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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 1; i++)
        {
            int sum = abs(a[i] - a[i + 1]);
            if (sum <= 1)
                a[i] = -1;
        }
        vector<int> v;
        for (auto x : a)
            if (x > 0)
                v.push_back(x);
        if (v.size() == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
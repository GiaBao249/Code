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

bool cmp(int &a, int &b)
{
    if (a & 0 && a > b)
        return a > b;
    return b > a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), v(n);
        int m = 0, b = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int sum = 0;
        int sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & 1)
                sum += a[i];
            else
                sum2 += a[i];
        }
        if (sum2 > sum)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
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
        bool ok = false;
        int x = 0;
        if (n == 2)
        {
            (a[0] % 2 == a[1] % 2) ? cout << "YES" << endl : cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            x += a[i];
            int sum = 0;
            for (int j = i + 1; j < n; j++)
            {
                sum += a[j];
            }
            if (sum % 2 == 1 && x % 2 == 1 || sum % 2 == 0 && x % 2 == 0)
            {
                ok = true;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
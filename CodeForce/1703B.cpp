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
        string s;
        cin >> s;
        vector<bool> check(26, false);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!check[s[i] - 'A'])
            {
                res += 2;
                check[s[i] - 'A'] = true;
            }
            else
                res += 1;
        }
        cout << res << endl;
    }
    return 0;
}
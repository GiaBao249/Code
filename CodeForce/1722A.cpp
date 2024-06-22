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
        bool ok = true;
        if (n > 5)
        {
            cout << "NO" << endl;
            continue;
        }
        unordered_map<char, int> mp = {{'T', 1}, {'i', 1}, {'m', 1}, {'u', 1}, {'r', 1}};
        for (char c : s)
        {
            if (mp.find(c) != mp.end() && mp[c] > 0)
                mp[c]--;
        }
        for (auto [a, b] : mp)
        {
            if (b != 0)
            {
                ok = false;
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
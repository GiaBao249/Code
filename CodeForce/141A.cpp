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
    string s1, s2, t;
    cin >> s1 >> s2 >> t;
    string s = s1 + s2;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    bool ok = true;
    if (t.size() < s.size())
    {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (s[i] != t[i])
        {
            ok = false;
            break;
        }
    }
    if (ok)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
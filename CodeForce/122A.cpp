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

bool lucky(int n)
{
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '4' && s[i] != '7')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    bool ok = false;
    vector<int> num;
    for (int i = 0; i < 1000; i++)
    {
        if (lucky(i))
            num.push_back(i);
    }
    for (auto x : num)
    {
        if (n % x == 0)
            ok = true;
    }

    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
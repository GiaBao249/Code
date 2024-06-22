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
        string s;
        cin >> s;
        int sum = 0;
        for (auto c : s)
        {
            if (c != '+')
                sum += c - '0';
        }
        cout << sum << endl;
    }
    return 0;
}
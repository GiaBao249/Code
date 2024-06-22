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
        int n = 8;
        vector<char> v;
        while (n--)
        {
            for (int i = 0; i < 8; i++)
            {
                char c;
                cin >> c;
                if (c != '.')
                    v.push_back(c);
            }
        }
        for (auto x : v)
            cout << x;
        cout << endl;
    }
    return 0;
}
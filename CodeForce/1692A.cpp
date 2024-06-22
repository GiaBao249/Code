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
        int cnt = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b > a)
            cnt++;
        if (c > a)
            cnt++;
        if (d > a)
            cnt++;
        cout << cnt << endl;
    }
    return 0;
}
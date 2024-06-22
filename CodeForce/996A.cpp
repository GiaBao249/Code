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
    int n;
    cin >> n;
    vector<int> a = {1, 5, 10, 20, 100};
    int cnt = 0;
    int i = 4;
    while (n != 0)
    {
        if (n >= a[i])
        {
            n -= a[i];
            cnt++;
        }
        else
        {
            i--;
        }
    }
    cout << cnt << endl;
    return 0;
}
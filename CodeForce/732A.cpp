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
    int k, r;
    cin >> k >> r;
    int cnt = 1;
    int sum = 0;
    int i = 1;
    if (k % 10 == r || k % 10 == 0)
    {
        cout << cnt << endl;
        return 0;
    }
    while (sum % 10 != r)
    {
        cnt++;
        i++;
        sum = k * i;
        if (sum % 10 == 0)
            break;
    }
    cout << cnt << endl;
    return 0;
}
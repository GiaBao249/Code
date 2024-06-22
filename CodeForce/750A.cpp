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
    int n, k;
    cin >> n >> k;
    int sum = k;
    int cnt = 0;
    int i = 1;
    while (true)
    {
        sum += 5 * i;
        i++;
        if (cnt == n || sum > 240)
            break;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> v1, v2, v3;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            v1.push_back(i);
        else if (a[i] == 2)
            v2.push_back(i);
        else if (a[i] == 3)
            v3.push_back(i);
    }
    int team = min({v1.size(), v2.size(), v3.size()});
    cout << team << endl;
    for (int i = 0; i < team; i++)
    {
        cout << v1[i] + 1 << " " << v2[i] + 1 << " " << v3[i] + 1 << endl;
    }
}
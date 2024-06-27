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
#include <limits>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int maxPos = max_element(a.begin(), a.end()) - a.begin();
    int minPos = min_element(a.begin(), a.end()) - a.begin();

    if (minPos > maxPos)
        swap(maxPos, minPos);
    int L = maxPos + 1;
    int R = n - minPos;
    int LR = minPos + 1 + (n - maxPos);
    int RL = maxPos + 1 + (n - minPos);
    cout << min({L, R, LR, RL}) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
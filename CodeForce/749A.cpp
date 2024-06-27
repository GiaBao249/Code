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
    vector<int> a;
    while (n >= 2)
    {
        a.push_back(2);
        n -= 2;
    }
    if (n == 1)
    {
        a.pop_back();
        a.push_back(3);
    }
    cout << a.size() << endl;
    for (auto x : a)
        cout << x << " ";
    cout << endl;
}
int main()
{
    Solve();
    return 0;
}
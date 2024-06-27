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
    string s;
    string t = "9890";
    int x = 1;
    if (n <= 4)
    {
        if (n == 1)
            cout << t[0] << endl;
        else if (n == 2)
            cout << 98 << endl;
        else if (n == 3)
            cout << 989 << endl;
        else
            cout << t << endl;
        return;
    }
    n -= 4;
    while (n--)
    {
        s += to_string(x);
        x++;
        if (x > 9)
            x = 0;
    }
    cout << t + s << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
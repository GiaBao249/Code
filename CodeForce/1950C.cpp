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
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    string s;
    cin >> s;
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    string x = (h < 12) ? "AM" : "PM";
    if (h == 0)
        h = 12;
    else if (h > 12)
    {
        h -= 12;
    }
    string hour = (h < 10) ? +"0" + to_string(h) : to_string(h);
    string minute = (m < 10) ? +"0" + to_string(m) : to_string(m);
    cout << hour << ":" << minute << " " << x << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
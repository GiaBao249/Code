#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s = 0;
        vector<pair<int, int>> v(4);
        for (int i = 0; i < 4; i++)
            cin >> v[i].first >> v[i].second;
        for (int i = 0; i < 4; i++)
        {
            int dx = v[i].first - v[0].first;
            int dy = v[i].second - v[0].second;
            int d = dx * dx - dy * dy;
            s = max(d, s);
        }
        cout << s << endl;
    }
    return 0;
}
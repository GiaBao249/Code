#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int res = 0;
    int cnt = 0;
    map<char, int> mp;
    for (char c : s)
        mp[c]++;
    for (auto x : mp)
    {
        if (x.first == ' ')
            cnt = x.second;
    }
    for (auto x : mp)
    {
        if (x.second >= 2)
            res += x.second;
    }
    cout << res - cnt << endl;
}

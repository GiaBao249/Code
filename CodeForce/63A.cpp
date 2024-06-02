#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> res;
    vector<pair<string, string>> v;
    while (n--)
    {
        string s, t;
        cin >> s >> t;
        v.push_back({s, t});
    }
    for (auto x : v)
        if (x.second == "rat")
            res.push_back(x.first);
    for (auto x : v)
        if (x.second == "woman" || x.second == "child")
            res.push_back(x.first);
    for (auto x : v)
        if (x.second == "man")
            res.push_back(x.first);
    for (auto x : v)
        if (x.second == "captain")
            res.push_back(x.first);
    for (auto x : res)
        cout << x << endl;
}

#include <bits/stdc++.h>

using namespace std;
vector<string> weightedUniformStrings(string s, vector<int> v)
{
    int n = s.size();
    vector<string> res;
    unordered_set<int> se;
    unordered_map<char, int> mp;
    for (auto x : s)
        mp[x]++;
    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
        if (x.second == 1)
            se.insert((x.first - 'a' + 1));
        else
        {
            for (int i = 2; i <= x.second; i++)
                se.insert((x.first - 'a' + 1) * i);
        }
    }
    int all = 0;
    for (auto x : s)
        all += x - 'a' + 1;
    se.insert(all);
    for (auto x : se)
        cout << x << " ";
    for (auto x : v)
    {
        if (se.find(x) != se.end())
            res.push_back("Yes");
        else
            res.push_back("No");
    }
    return res;
}

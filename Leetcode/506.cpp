#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int> &v)
{
    unordered_map<int, string> mp;
    vector<string> type{"Gold Medal", "Silver Medal", "Bronze Medal"};
    vector<int> score = v;
    sort(score.begin(), score.end(), greater<int>());
    for (int i = 0; i < v.size(); i++)
    {
        if (i < 3)
            mp[score[i]] = type[i];
        else
            mp[score[i]] = to_string(i + 1);
    }
    vector<string> res;
    for (auto it : v)
    {
        res.push_back(mp[it]);
    }
    return res;
}
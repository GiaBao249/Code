#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string> &words)
{
    vector<int> min_chr(26, INT_MAX);
    for (auto word : words)
    {
        vector<int> mp(26, 0);
        for (char c : word)
        {
            mp[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            min_chr[i] = min({min_chr[i], mp[i]});
        }
    }
    vector<string> res;
    for (int i = 0; i < 26; i++)
    {
        while (min_chr[i] > 0)
        {
            res.push_back(to_string(i + 'a'));
            min_chr[i]--;
        }
    }
    return res;
}
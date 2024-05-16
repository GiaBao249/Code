#include <bits/stdc++.h>
using namespace std;
// pattern = "abba", s = "dog cat cat dog"

bool wordPattern(string pattern, string s)
{
    stringstream ss(s);
    vector<string> words;
    string tmp = "";
    while (ss >> tmp)
        words.push_back(tmp);
    if (pattern.size() != words.size())
        return false;
    unordered_map<string, char> mp1;
    unordered_map<char, string> mp2;
    for (int i = 0; i < pattern.size(); i++)
    {
        char cur = pattern[i]; // key = a
        string tmp = words[i]; // key = dog

        if (mp1.count(tmp) && mp1[tmp] != cur)
            return false;
        else if (mp2.count(cur) && mp2[cur] != tmp)
            return false;
        mp1[tmp] = cur; // value = a
        mp2[cur] = tmp; // value = dog
    }
    return true;
}

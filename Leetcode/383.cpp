#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> mp;
    for (auto c : magazine)
        mp[c]++;
    for (auto c : ransomNote)
    {
        if (mp[c] > 0)
            mp[c]--;
        else
            return false;
    }
    return true;
}
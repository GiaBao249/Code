#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;
    else
    {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp1[s[i]] != mp2[t[i]])
                return false;
            else
            {
                mp1[s[i]] = i + 1;
                mp2[t[i]] = i + 1;
            }
        }
    }
    return true;
}
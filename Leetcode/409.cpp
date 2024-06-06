#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
    unordered_map<char, int> mp;
    for (char c : s)
        mp[c]++;
    int cnt = 0;
    bool ok = false;
    for (auto [a, b] : mp)
    {
        if (b % 2 == 0)
            cnt += b;
        else
        {
            ok = true;
            cnt += b - 1;
        }
    }
    if (ok)
        return cnt + 1;
    return cnt;
}
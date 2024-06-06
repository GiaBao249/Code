#include <bits/stdc++.h>
using namespace std;

int appendCharacters(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[j])
        {
            j++;
        }
    }
    return m - j;
}
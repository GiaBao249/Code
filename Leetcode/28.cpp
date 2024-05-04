#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int cnt = 0;
    int j = 0;
    int n = needle.length();
    for (int i = 0; i < haystack.length(); i++)
    {
        if (haystack[i] != needle[j])
        {
            j = 0;
            i = cnt;
            cnt++;
        }
        else
        {
            j++;
        }
        if (j == n)
            return cnt;
    }
    return -1;
}

int strstr(string a, string b)
{
    int res = 0;
    if (a.find(b) == string::npos)
        return -1;
    else
        res = a.find(b);
    return res;
}
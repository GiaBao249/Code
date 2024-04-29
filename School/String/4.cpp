#include <bits/stdc++.h>
using namespace std;

string test(string &s)
{
    unordered_map<string, int> mp;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        int cnt = 0;
        unordered_set<char> se;
        for (char c : word)
        {
            if (c == '-')
                break;
            cnt++;
            se.insert(c);
        }
        int maxChar = 0;
        for (auto it : se)
        {
            if (cnt > maxChar)
                maxChar = cnt;
        }
        mp[word] = maxChar;
    }
    string res;
    int maxChars = 0;
    for (auto x : mp)
    {
        if (x.second > maxChars)
        {
            maxChars = x.second;
            res = x.first;
        }
    }
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    cout << test(s) << endl;
}
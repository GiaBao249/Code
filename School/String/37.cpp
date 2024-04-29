#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    char k;
    cin >> k;
    unordered_map<char, int> mp;
    for (char c : s)
        mp[c]++;
    for (auto x : mp)
    {
        if (x.first == k)
            cout << x.second;
    }
}
#include <bits/stdc++.h>
using namespace std;

int solve()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (char x : s)
        mp[x]++;
    int max_fre = 0;
    for (auto it : mp)
        max_fre = max(it.second, max_fre);
    int remain = s.size() - max_fre;
    if (max_fre - 1 <= remain)
        return 1;
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}
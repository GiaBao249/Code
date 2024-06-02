#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int balance = 0;
    vector<pair<int, int>> prefix;
    for (int i = 0; i < s.size(); i++)
    {
        prefix.push_back({balance, i});
        if (s[i] == '(')
            balance++;
        else
            balance--;
    }
    sort(prefix.begin(), prefix.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
             if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first; });
    string res(s.size(), ' ');
    for (int i = 0; i < s.size(); i++)
        res[i] = s[prefix[i].second];
    cout << res << endl;
}
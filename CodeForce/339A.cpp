#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string res;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            res.push_back(s[i]);
            res += "+";
        }
    }
    res.pop_back();
    cout << res << " ";
    return 0;
}
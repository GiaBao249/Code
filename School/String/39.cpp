#include <bits/stdc++.h>
using namespace std;

bool x[26] = {false};

int TRY(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
            if (s[i] == s[j])
                return 0;
    }
    return 1;
}

int TRY2(string &s)
{
    set<char> se;
    for (char c : s)
        se.insert(c);
    if (se.size() == s.size())
        return 1;
    return 0;
}

int main()
{
    string s;
    cin >> s;
    cout << TRY2(s) << endl;
}
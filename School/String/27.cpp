#include <bits/stdc++.h>
using namespace std;

bool UPPER(char &s)
{
    if (s >= 'A' && s <= 'Z')
        return true;
    return false;
}

void Result(string &s)
{
    vector<char> res;
    res.push_back(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (!UPPER(s[i]))
        {
            res.push_back(s[i]);
        }
        else
        {
            res.push_back(' ');
            res.push_back(s[i]);
        }
    }
    for (auto x : res)
        cout << x;
}

int main()
{
    string s;
    cin >> s;
    Result(s);
}
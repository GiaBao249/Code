#include <bits/stdc++.h>
using namespace std;

bool CheckUPPER(char &s)
{
    if (s >= 'A' && s <= 'Z')
        return true;
    return false;
}

bool CheckLOWER(char &s)
{
    if (s >= 'a' && s <= 'z')
        return true;
    return false;
}

char UPPER(char &s)
{
    if (s >= 'A' && s <= 'Z')
        s += 32;
    return s;
}

char LOWER(char &s)
{
    if (s >= 'a' && s <= 'z')
        s -= 32;
    return s;
}

string TEST(string &s)
{
    string res;
    bool ok;
    int j;
    if (CheckUPPER(s[0]))
    {
        ok = true;
        res.push_back((s[0]) + 32);
    }
    else if (CheckLOWER(s[0]))
    {
        ok = false;
        res.push_back((s[0]) - 32);
    }
    for (int i = 1; i < s.size(); i += 2)
    {
        if (CheckLOWER(s[i]) && ok)
        {
            res.push_back(LOWER(s[i]));
            res.push_back(UPPER(s[i + 1]));
        }
        else if (CheckUPPER(s[i]) && !ok)
        {
            res.push_back(UPPER(s[i]));
            res.push_back(LOWER(s[i + 1]));
        }
    }
    // if (s.size() % 2 == 0)
    // {
    //     if (CheckLOWER(s[s.size() - 1]))
    //         res += s[s.size() - 1] - 32;
    //     else if (CheckUPPER(s[s.size() - 1]))
    //         res += s[s.size() - 1] + 32;
    // }
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    cout << TEST(s);
}

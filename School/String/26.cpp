#include <bits/stdc++.h>
using namespace std;

bool UPPER(char &s)
{
    if (s >= 'A' && s <= 'Z')
        return true;
    return false;
}

bool LOWER(char &s)
{
    if (s >= 'a' && s <= 'z')
        return true;
    return false;
}

bool check(string &s)
{
    bool space = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (space && !UPPER(s[i]))
        {
            return false;
        }
        space = isspace(i);
    }
    return true;
}

int main()
{
    string s;
    getline(cin, s);
    cout << boolalpha << check(s) << endl;
}
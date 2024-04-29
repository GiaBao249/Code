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

bool check(string &s1, string &s2)
{
    for (int i = 0; i < s2.size(); i++)
    {
        for (int j = 0; j < s1.size(); j++)
        {
            if (s2[i] != s1[i])
                return false;
            else
                continue;
        }
    }
    return true;
}

int main()
{
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << boolalpha << check(s1, s2);
}
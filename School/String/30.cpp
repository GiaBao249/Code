#include <bits/stdc++.h>
using namespace std;

bool x[26] = {false};

bool checkkytu(char &s)
{
    if (s >= 'a' && s <= 'z')
        return true;
    return false;
}

char check(string &s)
{
    for (char c : s)
    {
        if (checkkytu(c))
            x[c - 'a'] = true;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (!x[i])
        {
            return 'a' + i;
        }
    }
    return '\0';
}

int main()
{
    string s;
    cin >> s;
    if (check(s) != '\0')
        cout << check(s);
    else
        cout << "There is no missing letter!";
}
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

bool checkinhoa(string &s)
{
    int i = 0;
    bool ok = false;
    while (UPPER(s[i]))
    {
        ok = true;
        i++;
    }
    if (LOWER(s[i]))
        ok = false;
    return ok;
}

bool checkinthuong(string &s)
{
    int i = 0;
    bool ok = 0;
    while (LOWER(s[i]))
    {
        ok = true;
        i++;
    }
    if (UPPER(s[i]))
        ok = false;
    return ok;
}
int main()
{
    string s;
    cin >> s;
    cout << "1.Check in hoa " << endl;
    cout << "2.Check in thuong " << endl;
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << boolalpha << checkinhoa(s);
        break;
    case 2:
        cout << boolalpha << checkinthuong(s);
        break;
    default:
        break;
    }
}
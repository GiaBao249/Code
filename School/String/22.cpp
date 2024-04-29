#include <bits/stdc++.h>
using namespace std;

bool checkKytu(char &s)
{
    if (s >= 'a' && s <= 'z' || s <= 'A' && s >= 'Z')
        return true;
    return false;
}

bool checkNums(char &s)
{
    if (s >= '0' && s <= '9')
        return true;
    return false;
}

string result(string &s)
{
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (checkKytu(s[i]) || checkNums(s[i]) || s[i] == ' ')
            res += s[i];
    }
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    cout << result(s) << endl;
}
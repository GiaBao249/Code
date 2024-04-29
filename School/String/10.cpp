#include <bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    string res = "";
    for (int i = s.size() - 1; i < s.size(); i--)
    {
        res += s[i];
    }
    return res;
}

bool check(string s)
{
    string res = reverse(s);
    if (res == s)
        return true;
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    cout << boolalpha << check(s) << endl;
}
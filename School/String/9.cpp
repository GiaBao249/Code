#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
            return true;
    }
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    cout << boolalpha << check(s) << endl;
}
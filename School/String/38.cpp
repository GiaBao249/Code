#include <bits/stdc++.h>
using namespace std;

string RESULT(string &s, int k)
{
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != k)
            res += s[i];
        else
            continue;
    }
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    char k;
    cin >> k;
    cout << RESULT(s, k);
}
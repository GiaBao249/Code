#include <bits/stdc++.h>
using namespace std;

string Try(string &s)
{
    // int sum = 0;
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < s.size(); i++)
    {
        int sum = 0;
        if (s[i] >= 48 && s[i] <= 57)
        {
            if (s[i] != ' ')
            {
                sum = sum * 10 + (s[i] - '0');
            }
            else
            {
                s1.push_back(sum);
                break;
            }
        }
    }
    return s1;
}

int main()
{
    string s;
    getline(cin, s);
    cout << Try(s);
}
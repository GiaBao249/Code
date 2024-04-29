#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string res1 = "";
    string res2 = "";
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
            res1 += s1[i];
        if (s1.size() - i > 0)
            res1 += s1[i];
        else
            break;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (s1[i] != s2[i])
            res2 += s2[i];
        if (s2.size() - i > 0)
            res2 += s2[i];
        else
            break;
    }
    int res = res1.size() - res2.size();
    cout << res << endl;
}
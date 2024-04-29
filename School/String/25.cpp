#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    string res = "";
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1' && s[i + 1] == '1')
        {
            res += s[i];
            j++;
        }
    }
    if (s[j] == 1)
        res += s[j];
    cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    string res;
    for (int i = 0; i < n; i++)
        s[i] = tolower(s[i]);
    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
        {
            continue;
        }
        else
        {
            res += '.';
            res += s[i];
        }
    }
    cout << res << endl;
}
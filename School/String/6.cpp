#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int res = 0;
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] == 'e' && s[i + 2] == 'g')
            res++;
    }
    if (s[s.size() - 2] == 'e' && s[s.size()] == 'g')
        res += 1;
    cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int n = s.size();
    int res = 0;
    int flag = 0;
    if (s.size() == 1)
        return 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && flag)
        {
            break;
        }
        else if (s[i] != ' ')
        {
            res++;
            flag = 1;
        }
    }
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    cout << lengthOfLastWord(s) << endl;
}
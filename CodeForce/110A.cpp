#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    if (s.size() == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '7' || s[i] == '4')
            cnt++;
    }
    if (cnt == 7 || cnt == 4)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
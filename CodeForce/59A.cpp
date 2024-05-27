#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d1 = 0, d2 = 0;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (isupper(s[i]))
            d1++;
        else
            d2++;
    }
    for (int i = 0; i < n; i++)
    {
        if (d1 > d2)
            s[i] = toupper(s[i]);
        else if (d2 >= d1)
            s[i] = tolower(s[i]);
    }
    cout << s << endl;
}
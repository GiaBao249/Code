#include <bits/stdc++.h>
using namespace std;

void bai12(string &s, int l, int r)
{
    if (l == r)
        cout << s << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[i], s[l]);
            bai12(s, l + 1, r);
            swap(s[i], s[l]);
        }
    }
}

int main()
{
    string s;
    cin >> s;
    bai12(s, 0, s.length() - 1);
}
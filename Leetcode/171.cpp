#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string s)
{
    int x = 0;
    long long res = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int tmp = s[i] - 'A' + 1;
        res += tmp * pow(26, x);
        cout << res << endl;
        x++;
    }
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << titleToNumber(s);
}
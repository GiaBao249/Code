#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> se;
    for (int i = 0; i < n; i++)
        s[i] = tolower(s[i]);
    for (char c : s)
        se.insert(c);
    if (se.size() == 26)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
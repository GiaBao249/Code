#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> se;
    for (char c : s)
        se.insert(c);
    if (se.size() % 2 == 1)
        cout << "IGNORE HIM!" << endl;
    else
        cout << "CHAT WITH HER!" << endl;
}
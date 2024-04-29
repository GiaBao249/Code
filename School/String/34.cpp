#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, k;
    getline(cin, s);
    getline(cin, k);
    int i = 0;
    if (s.find(k) != string::npos)
        i = s.find(k);
    s.erase(i, k.length());
    cout << s;
}
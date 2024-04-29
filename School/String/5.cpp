#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    sort(s.rbegin(), s.rend(), greater<char>());
    cout << s;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    string k;
    getline(cin, k);
    int frist = s.find(k);
    int second = s.find(k, frist + 1);
    if (second != string ::npos)
        cout << second;
    else
        cout << -1;
}
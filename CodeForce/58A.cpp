#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string hello = "hello";
    int n = s.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == hello[j])
            j++;
    }
    if (j == hello.size())
        cout << "YES";
    else
        cout << "NO";
}

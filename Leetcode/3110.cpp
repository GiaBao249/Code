#include <bits/stdc++.h>
using namespace std;

int scoreOfString(string s)
{
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += abs(s[i] - s[i + 1]);
    }
    return sum;
}

int main()
{
    string s;
    cin >> s;
    cout << scoreOfString(s);
}
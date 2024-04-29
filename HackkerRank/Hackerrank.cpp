#include <bits/stdc++.h>

using namespace std;

string hackerrankInString(string s)
{
    string token = "hackerrank";
    int cnt = 0;
    for (char c : s)
    {
        if (c == token[cnt])
        {
            cnt++;
        }
    }
    if (cnt == token.size())
        return "YES";
    return "NO";
}

int main()
{
    string s;
    cin >> s;
    cout << hackerrankInString(s) << endl;
}
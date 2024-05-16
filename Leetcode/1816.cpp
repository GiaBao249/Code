#include <bits/stdc++.h>
using namespace std;

string truncateSentence(string s, int k)
{
    string res;
    int n = s.size();
    int cnt = 0;
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        temp += s[i];
        if (s[i] == ' ' || i == n - 1)
        {
            cnt++;
            res += temp;
            temp = "";
        }
        if (cnt == k)
            break;
    }
    if (res[res.size() - 1] == ' ')
    {
        res.pop_back();
    }
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    int k;
    cin >> k;
    cout << truncateSentence(s, k);
}
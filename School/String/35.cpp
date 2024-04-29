#include <bits/stdc++.h>
using namespace std;

string REVERSE(string s)
{
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--)
        res += s[i];
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word = "";
    vector<string> res;
    while (ss >> word)
    {
        if (word.size() % 2 == 1)
            res.push_back(REVERSE(word));
        else
            res.push_back(word);
    }
    for (auto x : res)
        cout << x << " ";
}
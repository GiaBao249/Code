#include <bits/stdc++.h>
using namespace std;

string reversed(string &s)
{
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        res += s[i];
    }
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
        if (word.size() >= 3)
        {
            string temp = reversed(word);
            res.push_back(temp);
        }
    }
    for (auto x : res)
        cout << x << " ";
}
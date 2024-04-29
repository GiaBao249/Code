#include <bits/stdc++.h>
using namespace std;

string funnyString(string s)
{
    string rev = s;
    reverse(rev.rbegin(), rev.rend());
    vector<int> v;
    vector<int> r;
    for (int i = 0; i < s.size() - 1; i++)
    {
        int tmp1 = abs((s[i] - 'a') - (s[i + 1] - 'a'));
        int tmp2 = abs((rev[i] - 'a') - (rev[i + 1] - 'a'));
        v.push_back(tmp1);
        r.push_back(tmp2);
        cout << tmp1 << " " << tmp2 << endl;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != r[i])
            return "Not Funny";
    }
    return "Funny";
}

int main()
{
    string s;
    cin >> s;
    cout << funnyString(s);
}
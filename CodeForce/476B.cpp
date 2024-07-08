#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void backtracking(string &s, int i, vector<string> &res)
{
    if (i == s.size())
    {
        res.push_back(s);
        return;
    }
    if (s[i] == '?')
    {
        s[i] = '+';
        backtracking(s, i + 1, res);

        s[i] = '-';
        backtracking(s, i + 1, res);
        s[i] = '?';
    }
    else
        backtracking(s, i + 1, res);
}

void Solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int question = 0;
    int sum = 0, target = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
            sum++;
        else
            sum--;
    }
    for (int i = 0; i < n; i++)
    {
        if (t[i] == '+')
            target++;
        else if (t[i] == '-')
            target--;
        else if (t[i] == '?')
            question++;
    }
    if (question == 0)
    {
        if (target == sum)
            cout << fixed << setprecision(12) << 1.0 << endl;
        else
            cout << fixed << setprecision(12) << 0.0 << endl;
        return;
    }
    string q = "";
    for (int i = 0; i < question; i++)
        q += '?';
    vector<string> tmp;
    vector<int> score;
    backtracking(q, 0, tmp);
    for (int i = 0; i < tmp.size(); i++)
    {
        int s = target;
        for (int j = 0; j < tmp[0].size(); j++)
        {
            if (tmp[i][j] == '+')
                s++;
            else
                s--;
        }
        score.push_back(s);
    }
    float x = 0;
    for (int i = 0; i < score.size(); i++)
    {
        if (score[i] == sum)
            x++;
    }
    cout << fixed << setprecision(12) << 1.0 * x / score.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
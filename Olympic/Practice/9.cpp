#include <bits/stdc++.h>
using namespace std;

int x[100];
string s;
vector<string> res;
vector<bool> check(s.size(), false);
string cur = "";
int k;
void Try1(int l, int r, string s)
{
    if (l == r)
        cout << s << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            Try1(l + 1, r, s);
            swap(s[l], s[i]);
        }
    }
}

void Try2(string &s, int l, vector<string> &res, int k, string &cur)
{
    if (cur.size() == k)
    {
        res.push_back(cur);
        return;
    }

    for (int i = l; i < s.size(); i++)
    {
        cur.push_back(s[i]);
        Try2(s, i + 1, res, k, cur);
        cur.pop_back();
    }
}

void Try3(string &s, string cur, vector<string> &res, int k, int l, vector<bool> &check)
{
    if (cur.size() == k)
    {
        res.push_back(cur);
        return;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (!check[i])
            {
                cur.push_back(s[i]);
                check[i] = true;
                Try3(s, cur, res, k, l + 1, check);
                cur.pop_back();
                check[i] = false;
            }
        }
    }
}

int main()
{
    cin >> k >> s;
    Try3(s, cur, res, k, 0, check);
    for (auto it : res)
        cout << it << endl;
    return 0;
}
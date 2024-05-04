#include <bits/stdc++.h>
using namespace std;

vector<int> buildArray(vector<int> &v)
{
    vector<int> res;
    for (int i = 0; i < v.size() - 1; i++)
    {
        res.push_back(v[v[i]]);
    }
    return res;
}
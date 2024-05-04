#include <bits/stdc++.h>
using namespace std;
const int OFFSET = 30000;
int x[60001];
int singleNumber(vector<int> &v)
{
    memset(x, 0, sizeof(x));
    int res = 0;
    if (v.size() == 1)
        return v[0];
    for (int i = 0; i < v.size(); i++)
        x[v[i] + OFFSET]++;
    for (int i = 0; i < 60001; i++)
    {
        if (x[i] == 1)
        {
            res = i - OFFSET;
            break;
        }
    }
    return res;
}
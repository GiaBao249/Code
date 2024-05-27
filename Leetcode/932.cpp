#include <bits/stdc++.h>
using namespace std;

vector<int> beautifulArray(int n)
{
    vector<int> run{1};
    while (run.size() < n)
    {
        vector<int> res;
        for (auto i : run)
            if (2 * i - 1 <= n)
                res.push_back(2 * i - 1);
        for (auto i : run)
            if (2 * i <= n)
                res.push_back(2 * i);

        run = res;
    }
    return run;
}
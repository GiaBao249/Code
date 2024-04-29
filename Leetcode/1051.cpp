#include <bits/stdc++.h>
using namespace std;

int heightChecker(vector<int> &heights)
{
    vector<int> expected = heights;
    int n = heights.size();
    sort(heights.begin(), heights.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (heights[i] != expected[i])
            count++;
    }
    return count;
}
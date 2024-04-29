#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gemstones(vector<string> &arr)
{
    for (auto &str : arr)
    {
        sort(str.begin(), str.end());
    }
    string ans = "";
    string first = arr[0];
    string last = arr[arr.size() - 1];
    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
            return ans.size();
        ans += first[i];
    }
    return ans.size();
}

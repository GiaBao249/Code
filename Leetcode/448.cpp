#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    set<int> se;
    vector<int> res;
    for (auto x : nums)
        se.insert(x);
    for (int i = 1; i <= nums.size(); i++)
    {
        if (se.count(i) == 0)
            res.push_back(i);
    }
    return res;
}
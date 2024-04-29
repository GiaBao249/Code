#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int current = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[current] = nums[i];
            current++;
        }
    }
    return current;
}

int removeDuplicates(vector<int> &nums)
{
    int current = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[current])
        {
            nums[current] = nums[i];
            current++;
        }
    }
    return current + 1;
}
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (target == nums[mid])
            return mid;
        else if (target > nums[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int seachRecursion(vector<int> &nums, int target, int l, int r)
{
    int mid = (l + r) / 2;
    while (l <= r)
    {
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            return seachRecursion(nums, target, mid - 1, r);
        return seachRecursion(nums, target, l, mid + 1);
    }
}
int main()
{
    vector<int> v = {1, 4, 9, 12, 19, 25, 31, 46, 50, 57, 72};
    int n = v.size();
    int target;
    cin >> target;
    seachRecursion(v, target, 0, n - 1);
}
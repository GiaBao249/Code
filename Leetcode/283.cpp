#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
   // Input: nums = [0,1,0,3,12]
   // Output: [1,3,12,0,0]
   int n = nums.size();
   int current = 0;
   for (int i = 0; i < n; i++)
   {
      if (nums[i] != 0)
      {
         nums[current] = nums[i];
         current++;
      }
   }
   for (; current < n; i++)
   {
      nums[current] = 0;
   }
}

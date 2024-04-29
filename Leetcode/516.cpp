#include <bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int> &nums)
{
    // So sánh hai phần tử kế tiếp nhau (lấy phần tử nhỏ hơn) + lai
    // rồi tạo thành 2 cặp  đồng thời nếu qua tất cả các cặp thì so sánh cặp nào có lớn nhất thì in ra
    int res = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size(); i += 2)
    {
        res += nums[i];
    }
    return res;
}

int main()
{
    vector<int> v = {1, 2, 3, 2};
    cout << arrayPairSum(v);
}
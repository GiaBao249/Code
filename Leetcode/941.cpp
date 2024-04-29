#include <iostream>
#include <vector>

using namespace std;

bool validMountainArray(vector<int> &arr)
{
    // Đầu vào: arr = [0,3,2,1]
    //  Đầu ra: true
    int n = arr.size();
    bool isIncrease = true;
    if (n < 3)
        return false;
    for (int i = 0; (i + 1) < n; i++)
    {
        int j = i + 1;
        if (arr[i] == arr[j])
            return false;
        else if (arr[i] < arr[j])
        {
            if (isIncrease == true)
                continue;
            else
                return false;
        }
        else if (arr[i] > arr[j])
        {
            if (isIncrease == false)
            {
                continue;
            }
            else
            {
                if (i == 0)
                    return false;
            }
            isIncrease = false;
        }
    }
    if (isIncrease == false)
        return true;
    return false;
}
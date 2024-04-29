#include <iostream>
#include <vector>
using namespace std;

// Cho một mảng số nguyên nums, di chuyển tất cả các số nguyên chẵn ở đầu mảng theo sau là tất cả các số nguyên lẻ.
vector<int> sortArrayByParity(vector<int> &a)
{
    int n = a.size();
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (a[i] % 2 != 0)
        {
            if (a[j] % 2 == 0)
            {
                swap(a[i], a[j]);
            }
            else
                j--;
        }
        else
        {
            i++;
        }
    }
    return a;
}
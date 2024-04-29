#include <bits/stdc++.h>
using namespace std;

void duplicateZeros(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = n - 2; j >= i + 1; j--)
            {
                arr[j + 1] = arr[j];
            }
            if (i + 1 < n)
            {
                arr[i + 1] = 0;
                i++;
            }
        }
    }
}

// Cách tối ưu hơn
void duplicateZeros(vector<int> &arr)
{
    vector<int> newArr;
    int n = (int)arr.size();
    for (int i = 0; i < n; i++)
    {
        newArr.push_back(arr[i]);
        if (arr[i] == 0)
        {
            newArr.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = newArr[i];
    }
}
int main()
{
    int arr[] = {1, 0, 2, 3, 0, 4, 5, 0};
    vector<int> a(arr, arr + sizeof(arr) / sizeof(int));
    duplicateZeros(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}
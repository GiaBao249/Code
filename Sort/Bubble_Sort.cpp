#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int main()
{
    vector<int> v = {1, 5, 2, 4, 9};
    bubbleSort(v);
    for (auto x : v)
        cout << x << " ";
}
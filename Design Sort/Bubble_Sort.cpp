#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
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
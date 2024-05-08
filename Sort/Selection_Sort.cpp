#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[minIndex] > a[j])
                minIndex = j;
        }
        if (minIndex != i)
        {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

int main()
{
    vector<int> v = {1, 5, 2, 4, 9};
    selectionSort(v);
    for (auto x : v)
        cout << x << " ";
}
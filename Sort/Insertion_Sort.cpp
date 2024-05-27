#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int ai = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > ai)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = ai;
    }
}

int main()
{
    vector<int> v = {50, 61, 24, 13, 73, 99, 51, 2};
    insertionSort(v);
    for (auto x : v)
        cout << x << " ";
}
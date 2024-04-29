#include <iostream>
using namespace std;

int Partition(int a[], int l, int r)
{
    int i, j, x;
    i = l - 1;
    x = a[r];
    for (int j = l; j < r; j++)
    {
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i++;
}

int QuickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int q = Partition(a, l, r);
        QuickSort(a, q + 1, r);
        QuickSort(a, l, q - 1);
    }
}

int main()
{
    int a[5] = {1, 3, 4, 5, 7};
    QuickSort(a, 0, 5);
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
}
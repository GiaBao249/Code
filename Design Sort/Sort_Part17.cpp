#include <bits/stdc++.h>
using namespace std;

void Try(int a[], int n)
{
    int i = 0, j = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (i >= 0 && j >= 0)
    {
        if (a[i] < a[i + 1])
            break;
        if (a[i] > a[j])
            swap(a[i], a[j]);
        cout << i + 1 << " " << j + 1 << endl;
        i++;
        j--;
    }
}

// Cách 2 dùng Quick Sort
void QuickSort(int a[], int l, int r)
{
    int i = l;
    int j = r;
    int chot = a[r];
    while (i <= j)
    {
        while (a[i] < chot)
            i++;
        while (a[j] > chot)
            j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            if (i != j)
                cout << i + 1 << " " << j + 1 << endl;
            ++i, --j;
        }
    }
    if (i < r)
        QuickSort(a, i, r);
    else
        QuickSort(a, l, j);
}

int main()
{
    int a[100], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    QuickSort(a, 0, n - 1);
}
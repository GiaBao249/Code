#include <bits/stdc++.h>
using namespace std;

void Sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int pos = i - 1, x = a[i];
        while (pos >= 0 && a[pos] >= x)
        {
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = x;
        cout << "Buoc " << i + 1 << ": ";
        for (int j = 0; j <= i; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[10] = {1, 4, 6, 5, 2, 3, 7, 8, 9, 0};
    Sort(a, 10);
}
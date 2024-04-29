#include <bits/stdc++.h>
using namespace std;

void Sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool ok = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                ok = true;
            }
        }
        if (ok)
        {
            cout << "Buoc " << i + 1 << ": ";
            for (int j = 0; j < n; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
        }
        else
            break;
    }
}

int main()
{
    int a[4] = {/*1, 4, 6, 5, 2, 3, 7, 8, 9, 0*/ 5, 3, 2, 7};
    Sort(a, 4);
}
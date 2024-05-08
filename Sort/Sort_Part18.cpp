#include <iostream>
using namespace std;

void insertSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int pos = i - 1, x = a[i];
        while (pos >= 0 && a[pos] >= x)
        {
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = x;
        cout << x << " " << pos + 1 << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertSort(a, n);
}
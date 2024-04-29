#include <bits/stdc++.h>
using namespace std;

void nhap(int *&a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> *(a + (n * i + j));
        }
    }
}

void xuat(int *&a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(a + (n * i + j)) << " ";
        }
        cout << endl;
    }
}

int duongcheo(int *&a, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += *(a + n * i + 1);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int *a;
    a = new int();
    nhap(a, n);
    xuat(a, n);
    cout << duongcheo(a, n) << endl;
}
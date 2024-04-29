#include <bits/stdc++.h>
using namespace std;

int n;
int a[100];

void Try(int i)
{
    if (i == 0)
        return;
    for (int j = 1; j < i; j++)
    {
        a[j] += a[j + 1];
        cout << a[j] << " ";
    }
    Try(i - 1);
    cout << "[";
    for (int j = 1; j <= i; j++)
    {
        cout << a[j];
        if (j == i)
            cout << "]" << endl;
        else
            cout << " ";
    }
    for (int j = i; j >= 1; j--)
    {
        a[j] -= a[j + 1];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        Try(n);
    }
}
#include <bits/stdc++.h>
using namespace std;

void Try(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    int l = 0, r = n - 1;
    while (l < r)
    {
        cout << a[l] << " " << a[r] << " ";
        l++, r--;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[100];
        int n;
        cin >> n;
        Try(a, n);
    }
}

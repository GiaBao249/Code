#include <bits/stdc++.h>
using namespace std;

void Try(int a[], int n)
{
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n); // 1 3 6
    for (int i = n - 1; i > 0; i--)
    {
        int sum = a[i] - a[i - 1];
        res = min(res, sum);
    }
    cout << res << endl;
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    Try(a, n);
}
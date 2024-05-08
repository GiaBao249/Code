#include <bits/stdc++.h>
using namespace std;

void Try(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int res = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] > k)
            res++;
    }
    cout << res << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a[100], k;
        cin >> n;
        cin >> k;
        Try(a, n, k);
    }
}
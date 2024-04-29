#include <bits/stdc++.h>
using namespace std;

void Try(int a[], int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    int stand = a[0];
    for (int i = 1; i < n; i++)
    {
        if (stand >= 1)
            res++;
        else
            break;
        stand = min(stand - 1, a[i]);
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
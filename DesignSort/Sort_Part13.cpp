#include <bits/stdc++.h>
using namespace std;

void Try(int a[], int b[], int n, int m)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    sort(a, a + n);
    sort(b, b + m);
    int cnt = 0;
    int i = n - 1, j = m - 1;
    while (j >= 0 && i >= 0)
    {
        if (a[i] > b[j])
        {
            cnt++;
            --i;
            --j;
        }
        else
            --j;
    }
    cout << cnt << endl;
}

int main()
{
    int a[100], b[100];
    int n, m;
    cin >> n >> m;
    Try(a, b, n, m);
}
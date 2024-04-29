#include <bits/stdc++.h>
using namespace std;

int a[100], x[100];
int n, sum = 0, k, ans = 0;

void Input()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}
void Try(int sum, int i, int pos)
{
    if (sum == k)
    {
        cout << "[";
        for (int j = 1; j < i; j++)
        {
            cout << x[j];
            if (j == i - 1)
                cout << "]";
            else
                cout << " ";
        }
        ans = 1;
        return;
    }
    for (int j = pos; j <= n; j++)
    {
        if (sum + a[j] <= k)
        {
            x[i] = a[j];
            Try(sum + a[j], i + 1, j + 1);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        Input();
        Try(0, 1, 1);
    }
}
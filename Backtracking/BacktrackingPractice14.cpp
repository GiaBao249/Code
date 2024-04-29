#include <bits/stdc++.h>
using namespace std;

int a[100], n, s, x[100], ok;

void input()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
}

void Try(int sum, int i, int pos)
{
    if (sum == s)
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
        ok = 1;
        return;
    }
    for (int j = pos; j <= n; j++)
    {
        if (sum + a[j] <= s)
        {
            x[i] = a[j];
            Try(sum + a[j], i + 1, j);
        }
    }
}
int main()
{
    input();
    Try(0, 1, 1);
    if (ok == 0)
        cout << "-1";
    else
        cout << endl;
}
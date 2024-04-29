#include <bits/stdc++.h>
using namespace std;

int a[100], x[100];
int n, k;

void Try()
{
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1)
    {
        cout << "No";
        return;
    }
    bool mark[sum / 2 + 1];
    memset(mark, false, sizeof(mark));
    for (int i = 0; i < n; i++)
    {
        for (int j = sum / 2; j >= a[i]; j--)
        {
            if (mark[j - a[i]] == 1 || j == a[i])
            {
                mark[j] = true;
            }
        }
    }
    if (mark[sum / 2])
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    Try();
}
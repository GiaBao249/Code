#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int a[100];
    int cnt = 0;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= a[k - 1] && a[i] > 0)
            cnt++;
    }
    cout << cnt << endl;
}
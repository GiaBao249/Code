#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= k)
            sum++;
        else
            sum += 2;
    }
    cout << sum << endl;
}
#include <bits/stdc++.h>
using namespace std;

int Try(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max(0, a[i] - i);
    }
    cout << ans << endl;
}
int main()
{
    int n;
    cin >> n;
    int a[100];
    Try(a, n);
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long l = 0;
        long long r = 2e9 + 7;
        while (l < r)
        {
            long long mid = l + (r - l + 1) / 2;
            long long res = 0;
            for (int i = 0; i < n; i++)
            {
                res += max(mid - a[i], 0LL);
            }
            if (res <= k)
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << endl;
    }
}
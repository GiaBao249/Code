#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s = 0;
    sort(a.begin(), a.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        if (s > sum / 2)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
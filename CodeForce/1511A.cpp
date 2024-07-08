#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (c1 >= c2)
        {
            if (a[i] == 3 || a[i] == 1)
                c1++;
        }
        else
        {
            if (a[i] == 3 || a[i] == 2)
                c2++;
        }
    }
    cout << c1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
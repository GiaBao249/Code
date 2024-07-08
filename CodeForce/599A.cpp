#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c > a + b)
        cout << (a + b) * 2 << endl;
    else if (a > b + c)
        cout << (b + c) * 2 << endl;
    else if (a + c < b)
        cout << (a + c) * 2 << endl;
    else
        cout << a + b + c << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
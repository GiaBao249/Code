#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    while (true)
    {
        int x = gcd(a, c);
        c -= x;
        if (c > 0)
        {
            int y = gcd(b, c);
            c -= y;
            if (c <= 0)
            {
                cout << "1" << endl;
                break;
            }
        }
        else
        {
            cout << "0" << endl;
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
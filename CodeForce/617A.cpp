#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    ll n;
    cin >> n;
    int cnt = 0;
    while (true)
    {
        if (n > 5)
            cnt++;
        n = n - 5;
        if (n < 5)
        {
            cnt++;
            break;
        }
    }
    cout << cnt << endl;
}
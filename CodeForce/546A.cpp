#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n, w;
    cin >> k >> n >> w;
    int total = 0;
    for (int i = 1; i <= w; i++)
    {
        total += k * i;
    }
    total -= n;
    if (total < 0)
        cout << 0 << endl;
    else
        cout << total << endl;
}
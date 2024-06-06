#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int h = 0, i = 1, sum = 0, temp = 0;
    while (sum <= n)
    {
        temp += i;
        sum += temp;
        h++;
        i++;
    }
    cout << h - 1 << endl;
}

int main()
{
    solve();
    return 0;
}
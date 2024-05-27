#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    while (true)
    {
        cnt++;
        a *= 3;
        b *= 2;
        if (a > b)
            break;
    }
    cout << cnt << endl;
    return 0;
}
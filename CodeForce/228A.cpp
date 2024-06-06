#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[4];
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        long long b;
        cin >> b;
        a[i] = b;
    }
    sort(a, a + 4);
    for (int i = 0; i < 3; i++)
    {
        if (a[i] == a[i + 1])
            cnt++;
    }
    cout << cnt << endl;
}
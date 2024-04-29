#include <bits/stdc++.h>
using namespace std;

int snt(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return n;
}

int bai16(int l, int r, int s)
{
    if (l == r)
        return s += snt(l);
    return bai16(l, r - 1, s + snt(r));
}

int main()
{
    int s = 0;
    int l, r;
    cin >> l >> r;
    cout << bai16(l, r, s) << endl;
}

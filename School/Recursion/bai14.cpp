#include <bits/stdc++.h>
using namespace std;

int bai14chan(int l, int r)
{
    if (l > r)
        return 0;
    else
    {
        if (l % 2 == 0)
            return l + bai14chan(l + 1, r);
        return bai14chan(l + 1, r);
    }
}

int bai14le(int l, int r)
{
    if (l > r)
        return 0;
    else
    {
        if (l % 2 != 0)
            return l + bai14le(l + 1, r);
        return bai14le(l + 1, r);
    }
}

int main()
{
    int chan, le;
    int l;
    cin >> l;
    int r;
    cin >> r;
    chan = bai14chan(l, r);
    le = bai14le(l, r);
    cout << "Sum of even numbers " << chan << endl;
    cout << "Sum of odd numbers " << le << endl;
}
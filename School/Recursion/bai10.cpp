#include <bits/stdc++.h>
using namespace std;

int bai10(int &a, int &b)
{
    if (b == 0)
        return a;
    return (b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << bai10(a, b);
}
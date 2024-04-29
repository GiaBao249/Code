#include <bits/stdc++.h>
using namespace std;

int bai13(int a, int b)
{
    if (b == 0)
        return 0;
    else if (b > 0)
    {
        return a + bai13(a, b - 1);
    }
    return -bai13(a, -b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << bai13(a, b);
}
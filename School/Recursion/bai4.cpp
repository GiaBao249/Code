#include <bits/stdc++.h>
using namespace std;

int bai4(int n)
{
    if (n <= 0)
        return 0;
    return n % 10 + bai4(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << bai4(n);
}

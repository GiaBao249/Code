#include <bits/stdc++.h>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    Swap(a, c);
    Swap(b, c);
    cout << a << " " << b << " " << c << endl;
}
#include <iostream>
using namespace std;

int Solve(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return Solve(n - 1) + Solve(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << Solve(n);
}
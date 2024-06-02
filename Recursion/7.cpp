#include <iostream>
using namespace std;

int Solve(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return Solve(n - 1, k - 1) + Solve(n - 1, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << Solve(n, k);
}
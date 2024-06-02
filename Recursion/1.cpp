#include <iostream>
using namespace std;

int Solve(int n)
{
    if (n == 0)
        return 0;
    return n + Solve(n - 1);
}

int SolveArray(int a[], int n)
{
    if (n == 0)
        return 0;
    return a[n - 1] + SolveArray(a, n - 1);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << SolveArray(a, n) << endl;
}
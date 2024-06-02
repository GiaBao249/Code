#include <iostream>
#include <math.h>
using namespace std;

int Solve(int n)
{
    if (n == 1)
        return 1;
    return n * n + Solve(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << Solve(n) << endl;
}
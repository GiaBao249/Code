#include <iostream>
using namespace std;

char Dex(int n)
{
    if (n > 10)
        return 'A' + (n - 10);
    return '0' + n;
}

string Solve(int n)
{
    if (n == 0)
        return "";
    int s = n % 16;
    return Solve(n / 16) + Dex(s);
}

int main()
{
    int n;
    cin >> n;
    cout << Solve(n) << endl;
}
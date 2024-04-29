#include <iostream>
using namespace std;

int Max(int *a, int *b)
{
    if (*a > *b)
        return *a;
    return *b;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int *a = &n;
    int *b = &m;
    int res = Max(a, b);
    cout << res << endl;
}
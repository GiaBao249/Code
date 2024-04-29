#include <iostream>
using namespace std;

int Sum(int &a, int &b)
{
    return a + b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << Sum(n, m);
}

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int *a = &n;
    int *b = &m;
    cout << *a + *b;
}

#include <iostream>
using namespace std;

void Input(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> *(a + i);
}

void Output(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << *(a + i) << " ";
}
int main()
{
    int n, a[100];
    cin >> n;
    Input(a, n);
    Output(a, n);
    return 0;
}

#include <iostream>
using namespace std;

void Input(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> *(a + i);
}

int Output(int a[], int n)
{
    int res = *(a + 0);
    for (int i = 1; i < n; i++)
    {
        if (res < *(a + i))
        {
            res = *(a + i);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    Input(a, n);
    cout << Output(a, n);
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    int b[100];
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        b[a] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
}

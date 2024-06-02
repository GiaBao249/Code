#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool ok = false;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            ok = true;
            break;
        }
    }
    if (ok)
        cout << "HARD" << endl;
    else
        cout << "EASY" << endl;
}
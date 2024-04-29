#include <bits/stdc++.h>
using namespace std;

bool cmp(int *a, int *b)
{
    return *a > *b;
}

int main()
{
    int *a, *b;
    int n, m;
    cin >> n >> m;
    a = &n, b = &m;
    if (cmp(a, b))
        cout << "The number " << *a << " is larger " << endl;
    else
        cout << "The number " << *b << " is larger " << endl;
}
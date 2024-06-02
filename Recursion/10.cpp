#include <iostream>
using namespace std;

string Solve(int a[], int n, string s)
{
    if (n == 0)
        return s;
    return Solve(a, n - 1, s += to_string(a[n - 1]) + " ");
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string s = Solve(a, n, "");
    cout << s << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            s += "I hate ";
        else if (i % 2 == 1)
            s += "I love ";

        if (i == n - 1)
            s += "it ";
        else
            s += "that ";
    }
    cout << s << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int i = 1;
        while (n > 0)
        {
            if (n % 10 > 0)
                v.push_back(n % 10 * i);
            i *= 10;
            n /= 10;
        }
        cout << v.size() << endl;
        for (auto x : v)
        {
            if (x > 0)
                cout << x << " ";
        }
        cout << endl;
    }
}
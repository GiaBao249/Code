#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p, q;
    set<int> se;
    cin >> p;
    while (p--)
    {
        int x;
        cin >> x;
        se.insert(x);
    }
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        se.insert(x);
    }
    if (se.size() == n)
        cout << "I become the guy.";
    else
        cout << "Oh, my keyboard!";
}

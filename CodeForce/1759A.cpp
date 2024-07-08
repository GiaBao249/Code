#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string duma;
    for (int i = 0; i < 20; i++)
    {
        duma += "Yes";
    }
    if (duma.find(s) != string ::npos)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
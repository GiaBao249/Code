#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <limits>
#include <math.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int quest = 0, pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B' || s[i] == 'R')
        {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
        if (s[i] == '?')
            quest++;
    if (quest == n)
    {

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                cout << 'B';
            else
                cout << 'R';
        }
        cout << endl;
        return;
    }
    else
    {
        for (int i = pos; i > 0; i--)
        {
            if (s[i] == 'R')
                s[i - 1] = 'B';
            else if (s[i] == 'B')
                s[i - 1] = 'R';
        }
        for (int i = pos; i < n - 1; i++)
        {
            if (s[i + 1] == '?')
            {
                if (s[i] == 'B')
                    s[i + 1] = 'R';
                else if (s[i] == 'R')
                    s[i + 1] = 'B';
            }
        }
        cout << s << endl;
    }
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
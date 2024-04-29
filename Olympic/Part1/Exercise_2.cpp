#include <bits/stdc++.h>
using namespace std;

// D - Double String

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> a(n);
        map<string, bool> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            bool ok = 0;
            for (int j = 1; j < a[i].size(); j++)
            {
                string t1 = a[i].substr(0, j);
                string t2 = a[i].substr(j);
                if (mp[t1] && mp[t2])
                    ok = 1;
            }
            cout << ok << "\n";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0 && n > 2)
        cout << "Yes";
    else
        cout << "No";
}
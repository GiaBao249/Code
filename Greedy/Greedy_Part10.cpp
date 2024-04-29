#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000001;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        priority_queue<long long, vector<long long>, greater<long long>> Q;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            Q.push(x);
        }
        int ans = 0;
        while (Q.size() > 1)
        {
            int x = Q.top();
            Q.pop();
            int y = Q.top();
            Q.pop();
            ans = (ans + x + y) % MOD;
            Q.push(x + y);
        }
        cout << ans << endl;
    }
}
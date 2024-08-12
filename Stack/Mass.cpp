#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const int maxn = 0;
/*
 /\_/\
(= >_<)
/ >  \>
*/

void Solve()
{
    string s;
    cin >> s;
    stack<ll> st;
    unordered_map<char, int> mp = {{'C', 12}, {'H', 1}, {'O', 16}};
    ll sum = 0, tmp = 0;
    for (int i = 0; i < sz(s); i++)
    {
        if (s[i] == '(')
            st.push(-1);
        else if (!st.empty() && (s[i] == ')'))
        {
            int x = 1;
            if (i + 1 < sz(s) && (s[i + 1] - '0') >= 2 && (s[i + 1] - '0' <= 9))
                x = s[i + 1] - '0';
            while (!st.empty() && st.top() != -1)
            {
                tmp += st.top();
                st.pop();
            }
            st.pop();
            tmp *= x;
            if (x != 1)
                i++;
            st.push(tmp);
            tmp = 0;
        }
        else if ((s[i] - '0') >= 2 && (s[i] - '0' <= 9))
        {
            int x = st.top();
            st.pop();
            st.push(x * (s[i] - '0'));
        }
        else
            st.push(mp[s[i]]);
    }
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    cout << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("Task.inp", "r"))
    {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
    Solve();
    return 0;
}
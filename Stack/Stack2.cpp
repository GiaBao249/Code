#include <bits/stdc++.h>

#define el cout << "\n"
#define file ""
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define maxn 1000006

using namespace std;
string s;
int ans, cnt, res, st[maxn], a[maxn], top;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    f0(i, s.size())
    {
        if (s[i] == '(')
            st[++top] = i;
        else if (top)
        {
            a[i] = 1;
            a[st[top--]] = 1;
        }
    }
    f0(i, s.size())
    {
        if (a[i] == 1)
        {
            cnt++;
            if (cnt > ans)
                ans = cnt, res = 0;
            if (ans == cnt)
                res++;
        }
        else
            cnt = 0;
    }
    if (ans == 0)
        res = 1;
    cout << ans << ' ' << res;
    return 0;
}

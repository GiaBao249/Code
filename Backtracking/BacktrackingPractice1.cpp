#include <bits/stdc++.h>
using namespace std;

int n, k, s, ans = 0;
int x[100];

void Input()
{
    cin >> n >> k >> s;
}

void Try1(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if (i == k)
        {
            int sum = 0;
            for (int j = 1; j <= k; j++)
                sum += x[j];
            if (sum == s)
                ++ans;
        }
        else
            Try1(i + 1);
    }
}

void Try2(int sum, int cnt, int pos)
{
    if (sum == s && cnt == k)
        ++ans;
    else
    {
        for (int j = pos; j <= n; j++)
        {
            if (sum + j <= s && cnt + 1 <= k)
            {
                Try2(sum + 1, cnt + 1, j + 1);
            }
        }
    }
}

int main()
{
    while (1)
    {
        Input();
        if (n + s + k == 0)
            break;
        ans = 0;
        Try1(1);
        cout << ans << endl;
    }
}
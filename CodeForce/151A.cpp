#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    if (nl > 0)
    {
        int s1 = (k * l) / nl;
        int s2 = c * d;
        int s3 = p / np;
        vector<int> res = {s1, s2, s3};
        sort(res.begin(), res.end());
        cout << res[0] / n << endl;
    }
    return 0;
}
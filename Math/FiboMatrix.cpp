#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll x, y, z;

ll Mul(ll a, ll b)
{
    ll res = 0;
    a = a % z;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res + a) % z;
        }
        a = (a * 2) % z;
        b = b >> 1;
    }
    return res;
}

struct matrix
{
    ll X[2][2];
    friend matrix operator*(matrix a, matrix b)
    {
        matrix c;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                c.X[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    c.X[i][j] = (c.X[i][j] + Mul(a.X[i][k], b.X[k][j])) % z;
                }
            }
        }
        return c;
    }
};

matrix binPow(matrix a, ll n)
{
    if (n == 1)
        return a;
    matrix x = binPow(a, n / 2);
    x = x * x;
    if (n % 2 == 1)
        x = x * a;
    return x;
}

ll getFib(ll k)
{
    if (k <= 1)
        return k % z;

    matrix a;
    a.X[0][0] = 1;
    a.X[0][1] = 1;
    a.X[1][0] = 1;
    a.X[1][1] = 0;

    matrix res = binPow(a, k - 1);

    return res.X[0][0];
}

void Solve()
{
    cin >> x >> y >> z;
    ll value = __gcd(x, y);
    cout << getFib(value) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    Solve();
    return 0;
}
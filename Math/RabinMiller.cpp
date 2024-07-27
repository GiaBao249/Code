#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll Mul(ll a, ll b, ll c)
{
    ll res = 0;
    a = a % c;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res + a) % c;
        }
        b = b >> 1;
        a = (a << 1) % c;
    }
    return res;
}

ll P(ll a, ll k, ll n)
{
    a = a % n;
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = Mul(res, a, n);
        k = k >> 1;
        a = Mul(a, a, n);
    }
    return res;
}

bool check(ll a, ll n, ll k, ll m)
{
    ll mod = P(a, m, n);
    if (mod == 1 || mod == n - 1)
        return true;
    for (int i = 0; i < k; i++)
    {
        mod = (mod * mod) % n;
        if (mod == n - 1)
            return true;
    }
    return false;
}

int snt(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

bool RabinMiller(ll n)
{
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if (n < 2 || n % 2 == 0)
        return false;
    if (n < 11)
        return (n == 2 || n == 3 || n == 5 || n == 7);
    ll k = 0, m = n - 1;
    while ((m & 1) == 0)
    {
        m >>= 1;
        k++;
    }
    vector<int> checkSet;
    for (int i = 2; i <= 50; i++)
    {
        if (snt(i))
            checkSet.push_back(i);
    }
    for (ll a : checkSet)
    {
        if (!check(a, n, k, m))
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    if (RabinMiller(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

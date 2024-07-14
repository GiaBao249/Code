#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 1e6;

vector<int> primes;
vector<bool> isPrime;

void sieve()
{
    isPrime.assign(maxN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxN; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= maxN; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

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

bool test(long long a, long long n, long long k, long long m)
{
    long long mod = P(a, m, n);
    if (mod == 1 || mod == n - 1)
        return true;
    for (int l = 1; l < k; ++l)
    {
        mod = Mul(mod, mod, n);
        if (mod == n - 1)
            return true;
    }
    return false;
}

bool isSquare(long long n)
{
    long long c = sqrt(n);
    return c * c == n || (c + 1) * (c + 1) == n;
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
        if (!test(a, n, k, m))
            return false;
    }
    return true;
}

pair<int, int> countDivisors(long long n)
{
    if (n == 1)
        return {1, 1};

    vector<int> powV;
    for (auto p : primes)
    {
        int cnt = 0;
        while (n % p == 0)
        {
            n /= p;
            ++cnt;
        }
        if (cnt)
            powV.push_back(cnt);
        if (n == 1)
            break;
    }

    if (n > 1)
    {
        if (RabinMiller(n))
            powV.push_back(1);
        else if (isSquare(n))
            powV.push_back(2);
        else
        {
            powV.push_back(1);
            powV.push_back(1);
        }
    }

    int res = 1;
    for (auto i : powV)
        res *= (i + 1);

    return {powV.size(), res};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    long long n;
    cin >> n;
    pair<int, int> res = countDivisors(n);
    cout << res.first << " " << res.second << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> gcd(int n)
{
    vector<int> res;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i * i != n)
                res.push_back(n / i);
        }
    }
    return res;
}

int f(int a, int b)
{
    int s = 0;
    vector<int> v1 = gcd(a);
    vector<int> v2 = gcd(b);
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
                s += v1[i];
        }
    }
    return s;
}

long long S(int n)
{
    long long sum = 0;
    for (int a = 1; a < n; a++)
    {
        for (int b = a + 1; b <= n; b++)
        {
            sum += f(a, b);
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << S(n);
}
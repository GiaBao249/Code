#include <bits/stdc++.h>
using namespace std;

float Solve1(int &n)
{
    float s = 0;
    for (int i = 0; i < n - 1; i++)
    {
        float t = 0, m = 1;

        for (int j = i + 1; j < n; j++)
        {
            t = t + j;
            m = m * j;
        }
        s = s + t / m;
    }
    return s;
}

// Cach toi uu
float Solve2(int &n)
{
    float s = 0;
    float t[n], m[n];
    t[n - 1] = m[n - 1] = n - 1;
    for (int i = n - 2; i > 0; --i)
    {
        t[i] = t[i + 1] + i;
        m[i] = m[i + 1] * i;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        s += t[i + 1] / m[i + 1];
    }
    return s;
}

int main()
{
    int n = 5;
    cout << fixed << setprecision(5) << Solve2(n) << endl;
    return 0;
}
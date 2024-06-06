#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

float Solve1(int n)
{
    if (n == 0)
        return 1;
    return 0.5 * Solve1(n - 1);
}

float Solve2(int n)
{
    float s = 1;
    for (int i = 0; i < n; i++)
    {
        s *= 0.5;
    }
    return s;
}

float Solve3(int n)
{
    float s = 0;
    for (int i = 0; i < n; i++)
    {
        s += 1.0 / pow(2, i);
    }
    return s;
}

int dx(int a[20][20], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i][j] != a[j][i])
                return 0;
    return 1;
}

void SORT(int a[100], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j])
                swap(a[i], a[j]);
}

int main()
{
    ifstream fs("input.txt");
    ofstream out("output.txt");
    if (!fs || !out)
        return 0;
    int n, a[20][20];
    fs >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fs >> a[i][j];
    }
    int c[100], k = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += a[i][j];
            c[k++] = s;
        }
        out << s << " ";
    }
    SORT(c, n);
    int b[n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (c[i] == a[j][0])
            {
                b[i] = j + 1;
                break;
            }
        }
    }
    out << endl;
    out << dx(a, n) << endl;
    for (int i = 0; i < n; i++)
        if (b[i] > 0)
            out << b[i] << " ";
}
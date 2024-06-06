#include <bits/stdc++.h>
using namespace std;

float Solve1(int n, int x)
{
    if (n == 0)
        return 0;
    return sqrt(x + Solve1(n - 1, x));
}

float Solve2(int n, int x)
{
    float s = 0;
    while (n--)
        s = sqrt(x + s);
    return s;
}

int Size(string &s)
{
    int cnt = 0;
    while (s[cnt] != '\0')
        cnt++;
    return cnt;
}

void Solve3(string &s)
{
    int cnt = 0;
    string res = "", tmp = "";
    int maxx = 0;
    int a[20] = {0};
    int k = 0;
    for (int i = 0; i < Size(s); i++)
    {
        if (s[i] != ' ')
        {
            cnt++;
            tmp += s[i];
        }
        else
        {
            a[k++] = cnt;
            if (maxx < Size(tmp))
            {
                maxx = Size(tmp);
                res = tmp;
            }
            cnt = 0;
            tmp = "";
        }
    }
    for (int i = 0; i < 11; i++)
        if (a[i] > 0)
            cout << a[i] << " ";
    cout << endl;
    cout << res << endl;
}

bool snt(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void SORT(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
    }
}

// int main()
// {
//     ifstream fs("num_inp.txt");
//     ofstream out("num_out.txt");
//     if (!fs || !out)
//         return 0;
//     int n;
//     int cnt = 0;
//     fs >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         fs >> a[i];
//         if (snt(a[i]))
//             cnt++;
//     }
//     out << cnt << endl;
//     SORT(a, n);
//     for (int i = 0; i < n; i++)
//         out << a[i] << " ";
//     cout << endl;
//     fs.close();
//     out.close();
//     return 0;
// }

int main()
{
    ifstream fs("str_input.txt");
    ofstream out("str_output.txt");
    if (!fs || !out)
        return 0;
    string line;
    string s = "";
    string tmp = "";
    string test = "";
    int maxx = 0;
    while (getline(fs, line))
    {
        for (int i = Size(line) - 1; i >= 0; i--)
        {
            test += line[i];
            if (line[i] == ' ')
            {
                string a = "";
                for (int i = Size(test) - 2; i >= 0; i--)
                {
                    a += test[i];
                }
                out << a << endl;
                test = "";
                break;
            }
        }
        for (int i = 0; i < Size(line); i++)
            tmp += line[i];
        if (maxx < Size(tmp))
        {
            maxx = Size(tmp);
            s = tmp;
        }
        tmp = "";
    }
    out << s << endl;
    fs.close();
    out.close();
    return 0;
}
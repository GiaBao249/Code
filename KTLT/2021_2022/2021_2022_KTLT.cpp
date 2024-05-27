#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;

int cau1a(int a[], int n)
{
    if (n == 0)
        return 0;
    return a[n - 1] + cau1a(a, n - 1);
}

char cau1b_phu(int n)
{
    if (n < 10)
        return '0' + n;
    return 'A' + (n - 10);
}

string cau1b(int n)
{
    if (n == 0)
        return "";
    int mod = n % 16;
    return cau1b(n / 16) + cau1b_phu(mod);
}

void cau2a(string s)
{
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            cnt1++;
        if (s[i] == ',' || s[i] == ':' || s[i] == '!' || s[i] == ';' || s[i] == '?' || s[i] == '.')
            cnt2++;
    }
    cout << cnt1 << " " << cnt2 << endl;
}

void cau2b(string s)
{
    int cnt = 0;
    int a[20] = {-1};
    int k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ' && s[i] != ':' && s[i] != '?')
        {
            cnt++;
            a[k] = cnt;
        }
        else
        {
            cnt = 0;
            k++;
        }
    }
    for (int i = 0; i < 20; i++)
    {
        if (a[i] > 0)
            cout << a[i] << " ";
    }
}

string cau2c(string s)
{
    int cnt = 0;
    int Max_val = 0;
    string tmp = "";
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ' && s[i] != ':' && s[i] != '?')
        {
            tmp += s[i];
        }
        else
        {
            if (tmp.size() > Max_val)
            {
                Max_val = tmp.size();
                res = tmp;
            }
            tmp = "";
        }
    }
    return res;
}

bool scp(int n)
{
    int m = sqrt(n);
    return m * m == n;
}

bool oddven(int n)
{
    return n % 2;
}

void SORT(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // ifstream fs("input.txt");
    // int n;
    // int m;
    // fs >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    //     fs >> a[i];
    // fs >> m;
    // fs.ignore();
    // string s;
    // getline(fs, s);
    // cout << cau1a(a, n) << endl;
    // cout << cau1b(m) << endl;
    // cau2a(s);
    // cau2b(s);
    // cout << endl;
    // cout << cau2c(s) << endl;

    ifstream file("table.inp");
    ofstream output1("square.txt");
    ofstream output2("oddven.txt");
    ofstream output3("sort.txt");
    if (!file.is_open() || !output1.is_open() || !output2 || !output3)
        return 1;

    int n, m;
    int a[100][100];

    file >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            file >> a[i][j];
    }
    int cntChan = 0;
    int cntLe = 0;
    int chan[100];
    int le[100];
    int u = 0, v = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (scp(a[i][j]))
            {
                output1 << a[i][j] << " " << i + 1 << " " << j + 1 << endl;
            }
            if (oddven(a[i][j]))
            {
                cntLe++;
                le[u++] = a[i][j];
            }
            else
            {
                cntChan++;
                chan[v++] = a[i][j];
            }
        }
    }
    output2 << cntLe << endl;
    for (int i = 0; i < 100; i++)
    {
        if (le[i] > 0)
            output2 << le[i] << " ";
    }
    output2 << endl;
    output2 << cntChan << endl;
    for (int i = 0; i < 100; i++)
    {
        if (chan[i] > 0)
            output2 << chan[i] << " ";
    }

    for (int j = 0; j < m; j++)
    {
        int row[100];
        for (int i = 0; i < n; i++)
        {
            row[i] = a[i][j];
        }
        SORT(row, n);
        for (int i = 0; i < n; i++)
        {
            a[i][j] = row[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            output3 << (a[i][j]) << " ";
        output3 << endl;
    }

    file.close();
    output1.close();
    output2.close();
    output3.close();
    return 0;
}

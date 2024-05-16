#include <iostream>
using namespace std;
string s1, s2;
int c = 1;
int b[1002], n, m;
int a[4] = {0, 0, 0, 0};
void Count()
{
    s2 = '0' + s2 + '0';
    int l = m + 2;
    for (int i = 1; i < l; i++)
    {
        if (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '1') // thêm đường gạch ngang
            b[i]++;
        if (s1[i - 1] == '0' && s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '0')
        { // kết thúc I, T, F
            b[i]++;
            a[b[i]]++;
            b[i] == 0;
        }
        if (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && b[i] > 0)
        { // kết thúc chữ E;
            a[4]++;
            b[i] = 0;
        }
    }
}
int main()
{
    freopen("TEFI.inp", "r", stdin);
    freopen("TEFI.out", "w", stdout);
    cin >> n >> m >> s1;
    for (int i = 0; i < m; i++)
        b[i] = 0;
    s1 = '0' + s1 + '0';
    int i = 0;
    while (i < n)
    {
        cin >> s2;
        Count();
        s1 = s2;
        i++;
    }
    s2 = "";
    for (int i = 0; i < m + 2; i++)
        s2 = s2 + '0';
    Count();
    cout << "T= " << a[2] << "\nE= " << a[4] << "\nF= " << a[3] << "\nI= " << a[1];
    return 0;
}

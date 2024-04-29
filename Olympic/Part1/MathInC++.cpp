#include <iostream>
using namespace std;
#define ll long long

int Mod(ll a, ll b, ll c)
{
    ll s = 0;
    while (b > 0)
    {
        if (b & 1 == 1)
        {
            s = (s + a) % c;
        }
        a = (a << 1) & c;
        b = b >> 1;
    }
    return s;
}

int Power(ll a, ll b, ll c)
{
    ll s = 1;
    while (b > 0)
    {
        if (b & 1 == 1)
            s = Mod(s, a, c);
        b = b >> 1;
        a = Mod(a, a, c);
        cout << s << " " << a << " " << b << endl;
    }
    return s;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << Power(a, b, c);
}
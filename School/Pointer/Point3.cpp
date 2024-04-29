#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        float b;
        char c;
        int *m = &a;
        float *fx = &b;
        char *cht = &c;
        cin >> a >> b >> c;

        cout << "address of m " << &m << endl;
        cout << "address of fx " << &fx << endl;
        cout << "address of cht " << &cht << endl;

        cout << "value at address of m " << a << endl;
        cout << "value at address of fx " << b << endl;
        cout << "value at address of cht " << c << endl;

        cout << "address of m " << m << endl;
        cout << "address of fx " << fx << endl;
        cout << "address of cht " << cht << endl;

        cout << "value at address of m " << (*m) << endl;
        cout << "value at address of fx " << (*fx) << endl;
        cout << "value at address of cht " << (*cht) << endl;
    }
}
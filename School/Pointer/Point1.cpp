#include <iostream>
using namespace std;

int main()
{
    int m = 10;
    int n, o;
    int *z;

    z = &m; // z lưu địa chỉ của m;

    cout << "z stores the address of m " << z << endl;
    cout << "*z stores the value of m " << *z << endl;
    cout << "&m is the address of m " << &m << endl;
    cout << "&n is the address of n " << &n << endl;
    cout << "&o is the address of o " << &o << endl;
    cout << "&z is the address of z " << &z << endl;
}
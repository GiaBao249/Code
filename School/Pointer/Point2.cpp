#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        int *ab = &m;
        cout << ab << endl;
        cout << *ab << endl;
    }
}
#include <iostream>
using namespace std;

void Try(string *&a, int &l, int &r)
{
    if (l == r)
        cout << a << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(*(a + i), *(a + l));
            Try(a, l + 1, r);
            swap(*(a + i), *(a + l));
        }
    }
}
int main()
{
    string s;
    cin >> s;
    string *a = &s;
    Try(a, 0, s.size() - 1);
}
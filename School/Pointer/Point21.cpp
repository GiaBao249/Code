#include <bits/stdc++.h>
using namespace std;

int main()
{
    char *c;
    for (char i = 'A'; i < 'Z'; i++)
    {
        c = &i;
        cout << *c << endl;
    }
}

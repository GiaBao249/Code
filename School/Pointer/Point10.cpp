#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string *a = &s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        cnt++;
    }
    cout << cnt << endl;
}
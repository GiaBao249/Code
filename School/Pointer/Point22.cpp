#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[100];
    cin >> s;
    int cnt = 0;
    for (int i = 0; s[i] != '\0'; i++)
        cnt++;
    int l = 0;
    int r = cnt - 1;
    for (size_t i = l; i < r; i++)
    {
        swap(*(s + l), *(s + r));
        l++;
        r--;
    }
    for (int i = 0; s[i] != '\0'; i++)
        cout << *(s + i);
}

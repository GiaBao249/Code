#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[100];
    cin >> s;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (*(s + i) == 'a' || *(s + i) == 'e' || *(s + i) == 'i' || *(s + i) == 'o' || *(s + i) == 'u')
            cnt1++;
        else
            cnt2++;
    }
    cout << "Number of vowels : " << cnt1 << endl;
    cout << "Number of constant : " << cnt2 << endl;
}
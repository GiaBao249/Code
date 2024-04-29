#include <bits/stdc++.h>
using namespace std;

void TRY(string &s, int k)
{
    int res = 0;
    vector<char> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            res++;
            v.push_back(s[i]);
        }
    }
    if (res == k)
        for (auto x : v)
            cout << x;
    else if (res > k)
        // for (int i = 0; i < k; i++)
        //     cout << v[i];
        cout << "The number of vowels present in the string is less than " << k << endl;
    else
        cout
            << "he number of vowels present in the string is less than " << k << endl;
}

int main()
{
    string s;
    getline(cin, s);
    int k;
    cin >> k;
    TRY(s, k);
}
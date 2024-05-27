#include <bits/stdc++.h>
using namespace std;

int check(string s1, string s2)
{
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
        if (s1[i] - '0' > s2[i] - '0')
            return 1;
        else if (s1[i] - '0' < s2[i] - '0')
            return -1;
        else if (s1[i] - '0' == s2[i] - '0')
            continue;
    }
    return 0;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << check(s1, s2) << endl;
}

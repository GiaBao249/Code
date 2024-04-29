#include <bits/stdc++.h>
using namespace std;

long long ans;
void Try(string s, int k)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (k == 0)
            break;
        char c = s[s.size() - 1];
        int pos = s.size() - 1;
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[j] >= c)
            {
                c = s[j];
                pos = j;
            }
        }
        if (c > s[i])
        {
            swap(s[pos], s[i]);
            k--;
        }
    }
    cout << s << endl;
}

int main()
{
    int k;
    string s;
    cin >> s >> k;
    Try(s, k);
}
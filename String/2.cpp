#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<char> se(s.begin(), s.end());
        vector<char> v(se.begin(), se.end());
        reverse(v.begin(), v.end());
        unordered_map<char, char> mp;
        int i = 0;
        for (auto x : se)
            mp[x] = v[i++];
        for (int i = 0; i < n; i++)
            s[i] = mp[s[i]];
        cout << s << endl;
    }
}

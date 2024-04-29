#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &v)
{
    string ans = "";
    int n = v.size();
    sort(v.begin(), v.end());
    string first = v[0];
    string last = v[n - 1];
    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
            return ans;
        ans += first[i];
    }
    return ans;
}

int main()
{
    vector<string> v = {"dog", "racecar", "car"};
    int n = v.size();
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}
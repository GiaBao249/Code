#include <bits/stdc++.h>
using namespace std;

vector<int> duplicates(long long arr[], int n)
{
    unordered_map<long, long> mp;
    vector<int> res;
    for (long long i = 0; i < n; i++)
        mp[arr[i]]++;
    for (auto x : mp)
    {
        if (x.second >= 2)
            res.push_back(x.first);
    }
    sort(res.begin(), res.end());
    if (res.empty())
    {
        res.push_back(-1);
    }
    return res;
}
int main()
{

    ifstream input("fileInput.txt");
    int n;
    input >> n;
    long long a[10000];
    for (int i = 0; i < n; i++)
        input >> a[i];
    vector<int> res = duplicates(a, n);
    for (auto x : res)
        cout << x << " ";
}
#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> a, int n, long long s)
{
    long long sum = 0;
    vector<int> res;
    if (s == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                res.push_back(i + 1);
                res.push_back(i + 1);
                return res;
            }
        }
        res.push_back(-1);
        return res;
    }
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        while (sum > s && start <= i)
        {
            sum -= a[start];
            start++;
        }
        if (sum == s)
        {
            res.push_back(start + 1);
            res.push_back(i + 1);
            return res;
        }
    }
    res.push_back(-1);
    return res;
}

int main()
{
    ifstream input("fileInput.txt");
    int n;
    input >> n;
    long long s;
    input >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        input >> v[i];
    }
    vector<int> res = subarraySum(v, n, s);
    for (auto x : res)
        cout << x << " ";
    return 0;
}
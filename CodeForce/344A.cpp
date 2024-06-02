#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != v[i + 1])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}
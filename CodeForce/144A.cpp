#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int cnt = 0;
    int maxx = *max_element(a.begin(), a.end());
    int minn = *min_element(a.begin(), a.end());
    if (maxx == a[0] && minn == a[n - 1])
    {
        cout << cnt << endl;
        return 0;
    }
    if (maxx != a[0])
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == maxx)
            {
                for (int j = i; j > 0; j--)
                {
                    swap(a[j], a[j - 1]);
                    cnt++;
                }
                break;
            }
        }
    }
    if (minn != a[n - 1])
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == minn)
            {
                for (int j = i; j < n - 1; j++)
                {
                    swap(a[j], a[j + 1]);
                    cnt++;
                }
                break;
            }
        }
    }
    cout << cnt << endl;
}

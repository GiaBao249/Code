#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vMin, vMax;
    int d, sumTime;
    cin >> d >> sumTime;
    for (int i = 0; i < d; i++)
    {
        int a;
        cin >> a;
        vMin.push_back(a);
        cin >> a;
        vMax.push_back(a);
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < d; i++)
    {
        sum1 += vMin[i];
        sum2 += vMax[i];
    }
    if (sum1 <= sumTime && sum2 >= sumTime)
    {
        cout << "Yes" << endl;
        int res = sumTime - sum1;
        int i = 0;
        while ((res))
        {
            int tmp = vMin[i];
            vMin[i] += min(res, vMax[i] - vMin[i]);
            res -= min(res, vMax[i] - tmp);
            i++;
        }
        for (int j = 0; j < d; j++)
        {
            cout << vMin[j] << " ";
        }
    }
    else
        cout << "NO" << endl;
    return 0;
}
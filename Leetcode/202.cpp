#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n)
{
    unordered_set<int> se;
    if (n == 1)
        return 1;
    int tmp = n;
    while (true)
    {
        int res = 0;
        while (tmp > 0)
        {
            int a = tmp % 10;
            tmp /= 10;
            res += 1.0 * pow(a, 2);
        }
        if (res == 1)
            return true;

        if (se.find(res) != se.end())
            return 0;
        else
            se.insert(res);
        tmp = res;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << boolalpha << isHappy(n);
}
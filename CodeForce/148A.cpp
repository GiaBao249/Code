#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, l, m, n;
    cin >> k >> l >> m >> n;
    int d;
    cin >> d;
    vector<bool> damage(d + 1, false);

    for (int i = k; i <= d; i += k)
    {
        damage[i] = true;
    }
    for (int i = l; i <= d; i += l)
    {
        damage[i] = true;
    }
    for (int i = m; i <= d; i += m)
    {
        damage[i] = true;
    }
    for (int i = n; i <= d; i += n)
    {
        damage[i] = true;
    }

    int cnt = 0;
    for (int i = 1; i <= d; i++)
    {
        if (damage[i])
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <limits>
#include <math.h>
using namespace std;
#define ll long long
// No Pain No Gain!

vector<ll> prime(10000001);
void sang()
{
    for (int i = 0; i <= 10000000; i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(10000000); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 10000000; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

void Solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }
    string s;
    s += '2';
    for (int i = 0; i < 1000000; i++)
    {
        s += '3';
        if (s.size() == n)
            break;
    }
    cout << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // sang();
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
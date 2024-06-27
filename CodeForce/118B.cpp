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

void Solve()
{
    int n;
    cin >> n;
    int size = 2 * n + 1;
    for (int i = 0; i < size; i++)
    {
        int space = abs(n - i) * 2;
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }
        int num = n - abs(n - i);
        for (int j = 0; j <= num; j++)
        {
            if (j > 0)
                cout << " ";
            cout << j;
        }
        for (int j = num - 1; j >= 0; j--)
        {
            cout << " " << j;
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
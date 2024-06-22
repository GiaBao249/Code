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
#include <deque>
#include <numeric>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int minA = *min_element(a.begin(), a.end());
        int minB = *min_element(b.begin(), b.end());
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int A = a[i] - minA;
            int B = b[i] - minB;
            cnt += max(A, B);
        }
        cout << cnt << "\n";
    }
    return 0;
}
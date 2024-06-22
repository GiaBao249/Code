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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pivot = a[0];
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > pivot)
        {
            pivot = a[i];
            cnt++;
        }
        else if (a[i] < a[0])
        {
            swap(a[i], a[0]);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
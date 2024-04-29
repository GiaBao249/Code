#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority_queue<int> Q;                            // Hàng đợi ưu tiên => Max_Heap
    priority_queue<int, vector<int>, greater<int>> Q; // => Min_Heap
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Q.push(x);
    }
    int ans = 0;
    while (Q.size() > 1)
    {
        int x = Q.top();
        Q.pop();
        int y = Q.top();
        Q.pop();
        ans += x + y;
        Q.push(x + y);
    }
    cout << ans << endl;
}
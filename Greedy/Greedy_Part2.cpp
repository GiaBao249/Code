#include <bits/stdc++.h>
using namespace std;

// Idea : Xóa những phần tử xuất hiện nhiều nhất cho đến 1 thì dừng xong chạy đến phần tử khác và lập lại

int Try(string s, int k)
{
    map<char, int> mp;
    for (char x : s)
        mp[x]++;
    priority_queue<int> Q;
    for (auto it : mp)
        Q.push(it.second);
    while (k--)
    {
        int temp = Q.top();
        Q.pop();
        --temp;
        Q.push(max(temp, 0));
    }
    int ans = 0;
    while (!Q.empty())
    {
        ans += Q.top() * Q.top();
        Q.pop();
    }
    cout << ans << endl;
}

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    cout << Try(s, k);
}
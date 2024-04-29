#include <bits/stdc++.h>
using namespace std;

void TEST(vector<string> &res, int start, int end, string cur, int n)
{
    if (cur.length() == 2 * n)
    {
        res.push_back(cur);
        return;
    }
    if (start < n)
        TEST(res, start + 1, end, cur + "[", n);
    if (end < start)
        TEST(res, start, end + 1, cur + "]", n);
}

int main()
{
    int n;
    cin >> n;
    vector<string> result;
    TEST(result, 0, 0, "", n);
    for (auto x : result)
        cout << x << " ";
    cout << endl;
    return 0;
}
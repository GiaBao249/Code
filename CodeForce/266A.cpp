#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(s[i]);
        if (st.top() == s[i + 1])
        {
            st.pop();
            cnt++;
        }
    }
    cout << cnt << endl;
}
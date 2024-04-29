#include <bits/stdc++.h>
using namespace std;

string Solve(string s)
{
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isalpha(s[i]))
            st.push(string(1, s[i]));
        else
        {
            string o1 = st.top();
            st.pop();
            string o2 = st.top();
            st.pop();
            string res = o1 + o2 + s[i];
            st.push(res);
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin >> s;
    cout << Solve(s);
}
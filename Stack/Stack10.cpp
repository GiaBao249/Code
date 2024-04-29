#include <bits/stdc++.h>
using namespace std;

bool check(char s)
{
    if (s >= '0' && s <= '9')
        return true;
    return false;
}

int Solve(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (check(s[i]))
            st.push(s[i] - '0');
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int res = 0;
            if (s[i] == '+')
                res = a + b;
            else if (s[i] == '-')
                res = a - b;
            else if (s[i] == '*')
                res = a * b;
            else if (s[i] == '/')
                res = a / b;
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
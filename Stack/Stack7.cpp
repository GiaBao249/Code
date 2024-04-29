#include <bits/stdc++.h>
using namespace std;

int Solve(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            if (i - st.top() == 2)
                return 1;
            else if (s[st.top() + 1] == '(' && s[i - 1] == ')')
                return 1;
            else
                st.pop();
        }
    }
    return 0;
}

int main()
{
    string s;
    cin >> s;
    if (Solve(s))
        cout << "YES";
    else
        cout << "NO";
}
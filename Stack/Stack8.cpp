#include <bits/stdc++.h>
using namespace std;

int Solve(string s)
{
    int res = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            if (st.empty())
            {
                res++;
                st.push(i);
            }
            else
                st.pop();
        }
    }
    res += st.size() / 2;
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << Solve(s);
}
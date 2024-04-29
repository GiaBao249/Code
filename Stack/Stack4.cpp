#include <bits/stdc++.h>
using namespace std;

int Solve(string s)
{
    //))))()
    stack<int> st;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (!st.empty())
                st.pop();
            else
                res++;
        }
        else
            st.push(i);
    }
    res += st.size();
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << Solve(s);
}
#include <iostream>
#include <stack>
using namespace std;

// 26B - Regular Bracket Sequence
int Try(string s)
{
    int res = 0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                continue;
            else
            {
                st.pop();
                res += 2;
            }
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << Try(s) << endl;
}
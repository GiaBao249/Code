#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n;
void Solve()
{
    stack<vector<int>> st;
    for (int i = n; i >= 1; i--)
    {
        vector<int> v;
        v.push_back(i);
        st.push(v);
    }
    while (!st.empty())
    {
        vector<int> v;
        v = st.top();
        st.pop();
        if (v.size() == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << v[i];
            }
            cout << endl;
        }
        else
        {
            for (int i = n; i >= 1; i--)
            {
                bool ok = false;
                for (int j = 0; j < v.size(); j++)
                {
                    if (v[j] == i)
                    {
                        ok = true;
                        break;
                    }
                }
                if (!ok)
                {
                    vector<int> temp(v);
                    temp.push_back(i);
                    st.push(temp);
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    Solve();
}
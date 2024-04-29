#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    int n;
    cin >> n;
    while (n > 1)
    {
        st.push(n);
        n--;
    }
    int sum = 1;
    while (st.empty() == false)
    {
        sum *= st.top();
        st.pop();
    }
    cout << sum << endl;
}
#include <bits/stdc++.h>
using namespace std;

string TRY(int n)
{
    string res = to_string(n);
    if (res.size() <= 3)
        return res;
    int count = (res.size() - 1) / 3;
    string temp = res;
    for (int i = 1; i <= count; i++)
    {
        temp.insert(res.size() - (i * 3), ",");
    }
    return temp;
}

int main()
{
    int n;
    cin >> n;
    cout << TRY(n) << endl;
}

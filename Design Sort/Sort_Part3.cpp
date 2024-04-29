#include <bits/stdc++.h>
using namespace std;

void Sort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int pos = i - 1, x = a[i];
        while (pos >= 0 && a[pos] >= x)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
        cout << "Buoc " << i + 1 << ": ";
        for (int j = 0; j <= i; j++)
            cout << a[j] << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> v = {5, 7, 3, 2};
    Sort(v);
}
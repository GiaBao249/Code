#include <bits/stdc++.h>
using namespace std;

void Sort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
        cout << "buoc " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

void ReverseStepSort(vector<int> &a)
{
    int n = a.size();
    vector<int> res[n];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
        for (int j = 0; j < n; j++)
        {
            res[i].push_back(a[j]);
        }
    }
    for (int j = n - 2; j >= 0; j--)
    {
        cout << "Buoc " << j + 1 << ": ";
        for (auto x : res[j])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> v = {5, 7, 3, 2};
    ReverseStepSort(v);
}
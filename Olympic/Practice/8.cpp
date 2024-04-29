#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &v, int hang, int cot, int n)
{
    // doc
    for (int i = 0; i < hang; i++)
    {
        if (v[i][cot])
            return false;
    }

    // cheo chinh
    for (int i = hang, j = cot; i >= 0 && j >= 0; i--, j--)
    {
        if (v[i][j])
            return false;
    }

    // cheo phu
    for (int i = hang, j = cot; i >= 0 && j < n; i--, j++)
    {
        if (v[i][j])
            return false;
    }

    return true;
}

bool Queen(vector<vector<int>> &v, int hang, int n)
{
    if (hang == n)
    {
        return true;
    }
    bool res = false;
    for (int cot = 0; cot < n; cot++)
    {
        if (check(v, hang, cot, n))
        {
            v[hang][cot] = 1;
            if (Queen(v, hang + 1, n))
                return true;
            v[hang][cot] = 0;
        }
    }
    return false;
}

void Prinf(int n)
{
    vector<vector<int>> v(n, vector<int>(n, 0));
    if (!Queen(v, 0, n))
        cout << "khong co truong hop nao" << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Prinf(n);
    return 0;
}

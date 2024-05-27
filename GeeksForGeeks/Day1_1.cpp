#include <bits/stdc++.h>
using namespace std;

//? Input:
//? N = 10
//? A[] = {6,1,2,8,3,4,7,10,5}
//? Output: 9

// sort = 1 2 3 4 5 6 7 8 10

int missingNumber(vector<int> &a, int n)
{
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] != i || a[n - 1] == n)
            return i;
    }
    return -1;
}

int missingNumber(vector<int> &a, int n)
{
    vector<int> check(n, -1);
    for (int i = 1; i <= a.size(); i++)
        check[a[i]] = a[i];
    for (int i = 1; i <= check.size(); i++)
    {
        if (check[i] == -1)
            return i;
    }
    return -1;
}

int main()
{
    ifstream input("fileInput.txt");
    int n;
    input >> n;
    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
        input >> arr[i];
    cout << missingNumber(arr, n) << endl;
    input.close();
}

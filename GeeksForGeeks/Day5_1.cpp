//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Input:
// n = 13
// arr[] = {12, 16, 22, 30, 35, 39, 42,
//          45, 48, 50, 53, 55, 56}
// k = 4, x = 35
// Output: 39 30 42 45
// Explanation:
// First closest element to 35 is 39.
// Second closest element to 35 is 30.
// Third closest element to 35 is 42.
// And fourth closest element to 35 is 45.

class Solution
{
public:
    int BS(vector<int> a, int n, int x)
    {
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[mid] == x)
                return mid;
            else if (a[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        int i = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        int j = i - 1;
        if (j >= 0 && arr[j] == x)
            j--;

        vector<int> res;
        while (k--)
        {
            int upperDiff = INT_MAX;
            if (i < n)
                upperDiff = arr[i] - x;
            int lowerDiff = INT_MAX;
            if (j >= 0)
                lowerDiff = x - arr[j];

            if (upperDiff <= lowerDiff)
                res.push_back(arr[i++]);
            else
                res.push_back(arr[j--]);
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int n, k, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k >> x;
    Solution ob;
    auto ans = ob.printKClosest(arr, n, k, x);
    for (auto e : ans)
    {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}

// } Driver Code Ends
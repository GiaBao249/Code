//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int findClosest(int n, int k, int a[])
    {
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(abs(a[i] - k));
        }
        int tmp = *min_element(res.begin(), res.end());
        int s;
        for (int i = 0; i < n; i++)
        {
            if (tmp == abs(a[i] - k))
                s = a[i];
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.findClosest(n, k, arr) << endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int PowMod(long long int x, long long int n, long long int m)
    {
        long long res = 1;
        x = x % m;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                res = (res * x) % m;
            }
            x = (x * x) % m;
            n = n / 2;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long int x, n, m;
        cin >> x >> n >> m;
        Solution ob;
        long long int ans = ob.PowMod(x, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
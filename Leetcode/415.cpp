#include <bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2)
{
    int n = num1.size() - 1;
    int m = num2.size() - 1;
    int carry = 0;
    string ans = "";
    while (n >= 0 || m >= 0)
    {
        int a = (n < 0) ? 0 : num1[n] - '0';
        int b = (m < 0) ? 0 : num2[m] - '0';
        int sum = a + b + carry;
        ans += to_string(sum % 10);
        carry = sum / 10;
        m--;
        n--;
    }
    if (carry > 0)
        ans += to_string(carry);
    reverse(ans.begin(), ans.end());
    return ans;
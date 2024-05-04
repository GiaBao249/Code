#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]) || isdigit(s[i]))
        {
            temp += tolower(s[i]);
        }
    }
    string rev = temp;
    reverse(rev.rbegin(), rev.rend());
    if (temp == rev)
        return true;
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << isPalindrome(s);
}
#include <iostream>
using namespace std;

string Solve(int n, string s)
{
    if (n == 0)
        return s;
    else
    {
        int tmp = n % 10;
        return Solve(n / 10, s + to_string(tmp));
    }
}

string Solve1(int n, string s)
{
    if (n == 0)
        return "";
    return s[n - 1] + Solve1(n - 1, s);
}

int main()
{
    int n;
    cin >> n;
    string s = Solve(n, "");
    cout << s << endl;
    cout << Solve1(s.size(), s);
}
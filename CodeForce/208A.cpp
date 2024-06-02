#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int pos = 0;
    while ((pos = s.find("WUB", pos)) != string ::npos)
        s.replace(pos, 3, " ");
    stringstream ss(s);
    string word = "";
    string res = "";
    while (ss >> word)
    {
        if (!res.empty())
            res += " ";
        res += word;
    }
    cout << res << endl;
}

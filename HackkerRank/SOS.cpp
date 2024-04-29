#include <bits/stdc++.h>
using namespace std;

vector<string> splitString(string s, int k)
{
    vector<string> res;
    int startPos = 0;
    while (startPos < s.size())
    {
        res.push_back(s.substr(startPos, k));
        startPos += k;
    }
    return res;
}

int marsExploration(string s)
{
    int cnt = 0;
    vector<string> temp = splitString(s, 3);

    for (auto it : temp)
    {
        cout << it << endl;
        if (it != "SOS")
            cnt++;
    }
    return cnt;
}

int main()
{
    string s;
    getline(cin, s);
    cout << marsExploration(s);
}
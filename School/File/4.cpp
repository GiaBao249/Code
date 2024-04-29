#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream fs;
    fs.open("Test.txt", ios::in);
    if (!fs.is_open())
        return 0;
    else
    {
        int res = 0;
        string s;
        while (fs >> s)
            res++;
        fs.close();
        cout << res;
    }
}
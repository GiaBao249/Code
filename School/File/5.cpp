#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream fs1, fs2;
    fs1.open("Test.txt", ios::in);
    fs2.open("File_Copy.txt", ios ::out);
    if (!fs1.is_open() || !fs2.is_open())
        return 0;
    else
    {
        string s;
        while (getline(fs1, s))
        {
            fs2 << s << endl;
        }
    }
    fs1.close();
    fs2.close();
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream fs;
    fs.open("Test.txt");
    if (!fs.is_open())
        return 0;
    else
    {
        while (!fs.eof())
        {
            string s;
            getline(fs, s);
            cout << s << endl;
        }
        fs.close();
    }
}
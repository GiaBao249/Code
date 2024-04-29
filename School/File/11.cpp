#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void FoundLine(string &fileName, string &ss)
{
    ifstream file;
    file.open("MergeFile.txt");
    if (!file.is_open())
        return;
    int cnt = 0;
    bool ok = false;
    string line;
    while (getline(file, line))
    {
        cnt++;
        size_t foundIndex = line.find(ss);
        if (foundIndex != string::npos)
        {
            cout << cnt << endl;
            ok = true;
        }
    }
    if (!ok)
        cout << "Khong tim thay";
    file.close();
}

int main()
{
    string fileName = "MergeFile.txt";
    string ss;
    getline(cin, ss);
    FoundLine(fileName, ss);
}
#include <bits/stdc++.h>
using namespace std;

void Upper(string &s)
{
    int res = 0;
    for (char i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' || s[i] != '.' || s[i] != '!' || s[i] != '?' || s[i] != '\n')
        {
            res = i;
            break;
        }
    }
    s[res] = toupper(s[res]);
    for (int i = res + 1; i < s.size(); i++)
    {
        if (islower(s[i]) && s[i - 1] == ' ' || s[i - 1] == '.' || s[i - 1] == '!' || s[i - 1] == '?' || s[i - 1] == '\n')
        {
            s[i] = s[i] - 32;
        }
    }
}

void Treatment(string &fileNameIn, string &fileNameOut)
{
    ifstream fs(fileNameIn);
    if (!fs.is_open())
        return;
    ofstream ofs(fileNameOut);
    if (!ofs.is_open())
        return;
    string line;
    while (getline(fs, line))
    {
        Upper(line);
        ofs << line << endl;
    }
    fs.close();
    ofs.close();
}
int main()
{
    string file = "MergeFile.txt";
    string outFile = "Exercise 4.18.txt";
    Treatment(file, outFile);
    return 0;
}
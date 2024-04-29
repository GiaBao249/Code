#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void InputFile(string &s, string &fileName)
{
    ofstream file(fileName, ios::app);
    if (!file.is_open())
        return;
    file << s << endl;
    file.close();
}

void MegreFile(vector<string> &v, string &outFileName)
{
    ofstream outFile(outFileName);
    if (!outFile.is_open())
        return;
    for (auto it : v)
    {
        ifstream InputFile(it);
        if (!InputFile.is_open())
            continue;
        else
        {
            string line;
            while (getline(InputFile, line))
            {
                outFile << line << endl;
            }
        }
        InputFile.close();
    }
    outFile.close();
}

int main()
{
    string file1 = "File1.txt";
    string s1 = "Many vendors provide C++ compilers, including the Free Software Foundation, LLVM,Microsoft, Intel, Embarcadero, Oracle, and IBM.";
    string file2 = "File2.txt";
    string s2 = "C++ is a high-level, general-purpose programming language created by Danish computer scientist Bjarne Stroustrup.";
    string file3 = "File3.txt";
    string s3 = "It is almost always implemented in a compiled language.";
    string file4 = "File4.txt";
    string s4 = "Modern C++ currently has object-oriented, generic, and functional features, in addition to facilities for low-level memory manipulation \nFirst released in 1985 as an extension of the C programming language, it has since expanded significantly over time";
    InputFile(s1, file1);
    InputFile(s2, file2);
    InputFile(s3, file3);
    InputFile(s4, file4);
    vector<string> fileNames = {"File1.txt", "File2.txt", "File3.txt", "File4.txt"};
    string outFile = "MergeFile.txt";
    MegreFile(fileNames, outFile);
    return 0;
}
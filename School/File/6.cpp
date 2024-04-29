#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void InputFile(string &s, string fileName)
{
    ofstream file;
    file.open(fileName, ios::in);
    if (file.is_open())
    {
        file << s;
        file.close();
    }
    else
        cout << "Khong mo duoc file" << endl;
}

void Test(string newWord, string oldWord, string fileName)
{
    ifstream filein(fileName);
    ofstream fileout("Tmp.txt");
    if (!filein || !fileout)
        return;
    else
    {
        string tmp;
        while (getline(filein, tmp))
        {
            size_t i = 0;
            while ((i = tmp.find(oldWord, i)) != string::npos)
            {
                tmp.replace(i, oldWord.length(), newWord);
                i += newWord.length();
            }
            fileout << tmp << '\n';
        }
        filein.close();
        fileout.close();
        remove(fileName.c_str());
        rename("Tmp.txt", fileName.c_str());
    }
}

int main()
{
    string s = "C++ is a high-level, general-purpose programming language created by Danish computer scientist Bjarne Stroustrup \nFirst released in 1980 as an extension of the C programming language, it has since expanded significantly over time \nModern C++ currently has object-oriented, generic, and functional features, in addition to facilities for low-level memory manipulation \nIt is almost always implemented in a compiled language \nMany vendors provide C++ compilers,including the Free Software Foundation, LLVM, Microsoft, Intel, Embarcadero, Oracle, and IBM";
    string fileName = "CPlus.txt";
    InputFile(s, fileName);
    string oldWord;
    cin >> oldWord;
    string newWord;
    cin >> newWord;
    Test(newWord, oldWord, fileName);
    return 0;
}

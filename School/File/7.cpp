#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ofstream file;
    file.open("CPlus.txt", ios ::app);
    if (!file.is_open())
        return 0;
    else
    {
        string newWord;
        getline(cin, newWord);
        file << newWord;
        file.close();
    }
    return 0;
}
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void Mahoadulieu(const string &fileName, int n, const string &outFile)
{
    ifstream inFile(fileName, ios::binary);
    if (!inFile.is_open())
        return;

    ofstream outFileStream(outFile, ios::binary);
    if (!outFileStream.is_open())
        return;

    char c;
    while (inFile.get(c))
    {
        c += n;

        if (c > 255)
        {
            c = 0;
        }

        outFileStream.put(c);
    }

    inFile.close();
    outFileStream.close();
}

int main()
{
    string fileName = "MergeFile.txt";
    string outFile = "encoded.txt";
    int n;
    cin >> n;
    Mahoadulieu(fileName, n, outFile);
    return 0;
}

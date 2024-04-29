#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void splitFile(int &n, string &outFile, string &inputFileName)
{
    ifstream file(inputFileName, ios::binary);
    if (!file.is_open())
        return;
    int index = 1;
    string outFileName = outFile + "_" + to_string(index) + ".txt";
    ofstream outPutFile(outFileName, ios::binary);
    char cnt;
    int currentNSize = 0;

    while (file.get(cnt))
    {
        outPutFile.put(cnt);
        currentNSize++;
        if (currentNSize >= n)
        {
            outPutFile.close();
            index++;
            outFileName = outFile + "_" + to_string(index) + ".txt";
            outPutFile.open(outFileName, ios::binary);
            currentNSize = 0;
        }
    }
    outPutFile.close();
}

int main()
{
    string inputFileName;
    int n;
    string outFile;
    cin >> inputFileName >> n >> outFile;
    splitFile(n, outFile, inputFileName);
}
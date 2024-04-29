#include <bits/stdc++.h>
using namespace std;

void Khoiphucdulieu(string &inFile, string &outFile, int n)
{
    ifstream input;
    input.open(inFile, ios::binary);
    if (!input.is_open())
        return;

    ofstream output;
    output.open(outFile, ios::binary);
    if (!output.is_open())
        return;

    char c;
    while (input.get(c))
    {
        c -= n;
        if (c > 255)
        {
            c = 255;
        }
        output.put(c);
    }
    input.close();
    output.close();
}

int main()
{
    string inFile = "encoded.txt";
    string outFile = "dencoded.txt";
    int n;
    cin >> n;
    Khoiphucdulieu(inFile, outFile, n);
}
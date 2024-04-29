#include <bits/stdc++.h>
using namespace std;

vector<string> splitRow(string &row, char c)
{
    vector<string> words;
    stringstream ss(row);
    string word;
    while (getline(ss, word, c))
    {
        words.push_back(word);
    }
    return words;
}

void CSV(string &fileName)
{
    ifstream input;
    input.open("Exercise 4.14.csv");
    if (!input.is_open())
        return;
    string line;
    int cnt = 0;
    while (getline(input, line))
    {
        vector<string> row = splitRow(line, ',');
        for (auto it : row)
        {
            cout << " " << it << "\t";
        }
        cout << endl;
    }
    input.close();
}

int main()
{
    string s = "Exercise 4.14.csv";
    CSV(s);
}
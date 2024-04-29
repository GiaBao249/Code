#include <bits/stdc++.h>
using namespace std;

bool isVowels(char &s)
{
    if (s >= 'a' && s <= 'z')
    {
        if (s == 'a' || s == 'e' || s == 'u' || s == 'i' || s == 'o')
            return true;
    }
    return false;
}

void ReadFile(string &fileName)
{
    ifstream fs(fileName);
    if (!fs.is_open())
        return;
    int line = 0, word = 0, vowels = 0, consonants = 0;
    string words;
    string s;
    while (getline(fs, s))
    {
        line++;
        stringstream ss(s);
        while (ss >> words)
            word++;
        for (auto c : s)
        {
            if (isVowels(c))
                vowels++;
            else if (isalpha(c))
                consonants++;
        }
    }
    cout << "Number of lines :" << line << endl;
    cout << "Number of words :" << word << endl;
    cout << "Number of vowels :" << vowels << endl;
    cout << "Number of consonants:" << consonants << endl;
    fs.close();
}

int main()
{
    string s = "MergeFile.txt";
    ReadFile(s);
}

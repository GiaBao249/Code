#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string TEST(string &s)
{
    unordered_map<string, int> wordFre;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        unordered_map<char, int> charCount;
        for (char c : word)
            charCount[c]++;
        int maxCount = 0;
        for (auto it : charCount)
        {
            if (it.second > maxCount)
                maxCount = it.second;
        }
        wordFre[word] = maxCount;
    }
    string res;
    int maxChars = 0;
    for (auto x : wordFre)
    {
        if (x.second > maxChars)
        {
            maxChars = x.second;
            res = x.first;
        }
    }
    return res;
}

int main()
{
    string input;
    cout << "Input: ";
    getline(cin, input);

    string word = TEST(input);

    cout << word << endl;

    return 0;
}

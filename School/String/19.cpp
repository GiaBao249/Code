#include <iostream>
#include <string>
using namespace std;

void SWAP(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
                    s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
                {
                    SWAP(s[i], s[j]);
                }
            }
        }
    }
    cout << s << endl;
}
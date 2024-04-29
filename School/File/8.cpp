#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void bubbleSort(string v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main()
{
    ifstream file;
    file.open("Test.txt");
    if (!file.is_open())
        return 0;
    else
    {
        string s;
        int cnt = 0;
        while (getline(file, s))
            cnt++;
        file.clear();
        file.seekg(0, ios::beg);
        string *v = new string[cnt];
        for (int i = 0; i < cnt; i++)
        {
            getline(file, v[i]);
        }
        file.close();

        bubbleSort(v, cnt);

        for (int i = 0; i < cnt; i++)
        {
            cout << v[i] << endl;
        }
        delete[] v;
    }
    return 0;
}
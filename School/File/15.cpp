#include <bits/stdc++.h>
using namespace std;

int dem(string file)
{
    ifstream checkfile(file);
    if (!checkfile.is_open())
        return 0;
    string line;
    int cnt = 0;
    while (getline(checkfile, line))
    {
        cnt++;
    }
    checkfile.close();
    return cnt;
}

int TBC(string &fileName)
{
    ifstream input(fileName);
    if (!input.is_open())
        return 0;
    string line;
    int res = 0;
    int cnt = dem(fileName);
    if (cnt == 0)
        return 0;
    while (getline(input, line))
    {
        stringstream ss(line);
        int num;
        if (ss >> num)
            res += num;
    }
    input.close();
    if (res == 0)
        return 0;
    return res / cnt;
}

int main()
{
    string fileName = "Exercise 4.15.txt";
    double average = TBC(fileName);
    cout << "Average: " << average << endl;
    return 0;
}
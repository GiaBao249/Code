#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream fs;
    fs.open("Exercise 1.txt", ios::out);
    if (!fs.is_open())
        return 0;
    else
    {
        fs << "Không có việc gì khó\nChỉ sợ lòng không bền\nĐào núi và lấp biển\nQuyết chí ắt làm nên" << endl;
    }
    fs.close();
    return 0;
}
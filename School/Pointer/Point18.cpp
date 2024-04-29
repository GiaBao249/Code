#include <bits/stdc++.h>
using namespace std;

struct Point
{
    string info;
    string location;
};

int main()
{
    Point data;
    data.info = "John Alter";
    data.location = "Court Street";
    Point *ptrData = &data;
    cout << ptrData->info << " from " << ptrData->location << endl;
}

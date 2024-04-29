#include <bits/stdc++.h>
using namespace std;

struct Point
{
    string name;
    int id;
};

int main()
{
    Point P;
    P.name = "Alex";
    P.id = 1002;
    Point *ptrP = &P;
    cout << ptrP->name << " " << ptrP->id << endl;
}
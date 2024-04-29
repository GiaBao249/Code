#include <bits/stdc++.h>
using namespace std;

vector<string> results;

int values[10] = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
int EXPECTED_COUNT = 0;

void backtracking(int index, int curCount, int h, int m)
{
    for (int i = 0; i <= 1; i++)
    {
        if (i == 1)
        {
            curCount++;
            if (index <= 3)
            {
                h += values[index];
            }
            else
            {
                m += values[index];
            }
        }
        if (index == sizeof(values) / sizeof(values[0]) - 1)
        {
            if (curCount == EXPECTED_COUNT && h < 12 && m < 60)
            {
                string time = to_string(h) + ":" + (m < 10 ? "0" + to_string(m) : to_string(m));
                this->results.push_back(time);
            }
        }
        else
        {
            backtracking(index + 1, curCount, h, m);
        }
    }
}

vector<string> readBinaryWatch(int turnedOn)
{
    EXPECTED_COUNT = turnedOn;
    backtracking(0, 0, 0, 0);
    return this->results;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    set<char> se;
    for (char c : s)
    {
        if (isalpha(c))
            se.insert(c);
    }
    cout << se.size();
    return 0;
}
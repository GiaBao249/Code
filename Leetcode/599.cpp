#include <bits/stdc++.h>
using namespace std;

vector<string> findRestaurant(vector<string> &list1,
                              vector<string> &list2)
{
    vector<string> res;
    string words = "";
    unordered_map<string, int> mp;
    for (int i = 0; i < list1.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < list2.size(); j++)
        {
            if (list1[i] == list2[j])
            {
                sum = (i + j);
                mp[list2[j]] = sum;
            }
        }
    }
    int m = INT_MAX;
    for (auto x : mp)
    {
        if (x.second < m)
            m = x.second;
    }
    for (auto x : mp)
        if (x.second == m)
            res.push_back(x.first);
    return res;
}

// vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
// {
//     vector<pair<string, int>> a;
//     vector<string> res;
//     for (int i = 0; i < list1.size(); i++)
//     {
//         int sum;
//         for (int j = 0; j < list2.size(); j++)
//         {
//             if (list1[i] == list2[j])
//             {
//                 sum = i + j;
//                 if (a.empty())
//                     a.push_back({list2[j], sum});
//                 else
//                 {
//                     auto [u, v] = a[0];
//                     if (sum < v)
//                     {
//                         a.clear();
//                         a.push_back({list2[j], sum});
//                     }
//                     else if (sum == v)
//                     {
//                         a.push_back({list2[j], sum});
//                     }
//                 }
//             }
//         }
//     }
//     for (auto [u, v] : a)
//         res.push_back(u);
//     return res;
// }
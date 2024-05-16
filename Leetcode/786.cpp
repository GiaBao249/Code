#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
//! Sai ở 1 số test case
vector<int> kthSmallestPrimeFraction(vector<int> &v, int k)
{
    int n = v.size();
    int l = 0;
    int r = n - 1;
    set<float> tmp;

    while (l < n)
    {
        while (r > l)
        {
            float ps = 1.0 * v[l] / v[r];
            tmp.insert(ps);
            r--;
        }
        l++;
        r = n - 1;
    }

    vector<float> save(tmp.begin(), tmp.end());
    float target = save[k - 1];
    int left = 0, right = n - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        float midValue = 1.0 * v[mid] / v[n - 1];
        if (midValue < target)
            left = mid + 1;
        else
            right = mid;
    }
    int tu = v[left];
    int mau = v[n - 1];

    return {tu, mau};
}

vector<int> Test1(vector<int> &v, int k)
{
    int n = v.size();
    vector<pair<float, pair<int, int>>> res;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            res.push_back(make_pair((1.0 * v[i] / v[j]), make_pair(v[i], v[j])));
        }
    }
    sort(res.begin(), res.end());
    return {res[k - 1].second.first, res[k - 1].second.second};
}

//! Binary Search
vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    int n = arr.size();
    double left = 0, right = 1, mid;
    vector<int> res;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        int j = 1, total = 0, num = 0, den = 0;
        double maxFrac = 0;
        for (int i = 0; i < n; ++i)
        {
            while (j < n && arr[i] >= arr[j] * mid)
            {
                ++j;
            }

            total += n - j;

            if (j < n && maxFrac < arr[i] * 1.0 / arr[j])
            {
                maxFrac = arr[i] * 1.0 / arr[j];
                num = i;
                den = j;
            }
        }

        if (total == k)
        {
            res = {arr[num], arr[den]};
            break;
        }

        if (total > k)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    return res;
}
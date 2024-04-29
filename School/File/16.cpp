#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

// Main merge sort function
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

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

int TBC(string fileName)
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
    ifstream inFile("Exercise 4.16.txt");
    if (!inFile)
        return 1;

    vector<int> numbers;
    int num;
    while (inFile >> num)
        numbers.push_back(num);

    inFile.close();

    mergeSort(numbers, 0, numbers.size() - 1);

    int min_val = numbers.front();
    int max_val = numbers.back();
    double average = TBC("Exercise 4.16.txt");

    ofstream outFile("Output Exercise 4.16.txt");
    if (!outFile)
        return 1;

    for (auto it : numbers)
        outFile << it << endl;
    outFile << "Min: " << min_val << endl;
    outFile << "Max: " << max_val << endl;
    outFile << "Average: " << average << endl;
    outFile.close();
    return 0;
}

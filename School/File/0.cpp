#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void ReadDataFromFile(const string &fileName, vector<vector<int>> &matrix, int &rows, int &cols)
{
    ifstream inputFile(fileName);
    if (!inputFile.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }

    inputFile >> rows >> cols;

    matrix.resize(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();
}

void WriteDataToFile(const string &fileName, const vector<string> &data)
{
    ofstream outputFile(fileName);
    if (!outputFile.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }
    for (const string &line : data)
    {
        outputFile << line << endl;
    }
    outputFile.close();
}

vector<int> SumRows(const vector<vector<int>> &matrix)
{
    vector<int> rowSums;
    for (const auto &row : matrix)
    {
        int sum = 0;
        for (int val : row)
        {
            sum += val;
        }
        rowSums.push_back(sum);
    }
    return rowSums;
}

vector<int> SumCols(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> colSums(cols, 0);
    for (int j = 0; j < cols; ++j)
    {
        for (int i = 0; i < rows; ++i)
        {
            colSums[j] += matrix[i][j];
        }
    }
    return colSums;
}

pair<int, int> FindMinMax(const vector<vector<int>> &matrix)
{
    int minValue = matrix[0][0];
    int maxValue = matrix[0][0];
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            minValue = min(minValue, val);
            maxValue = max(maxValue, val);
        }
    }
    return make_pair(maxValue, minValue);
}

vector<pair<int, int>> MaxMinRows(vector<vector<int>> &v)
{
    vector<pair<int, int>> res;
    for (int i = 0; i < v.size(); i++)
    {
        int minVal = INT16_MAX;
        int maxVal = INT16_MIN;
        for (int j = 0; j < v[i].size(); j++)
        {
            minVal = min(minVal, v[i][j]);
            maxVal = max(maxVal, v[i][j]);
        }
        res.push_back({maxVal, minVal});
    }
    return res;
}

vector<pair<int, int>> MaxMinCols(vector<vector<int>> &v)
{
    vector<pair<int, int>> res;
    for (int i = 0; i < v[0].size(); i++)
    {
        int minVal = INT16_MAX;
        int maxVal = INT16_MIN;
        for (int j = 0; j < v.size(); j++)
        {
            minVal = min(minVal, v[i][j]);
            maxVal = max(maxVal, v[i][j]);
        }
        res.push_back({maxVal, minVal});
    }
    return res;
}

vector<int> SortMatrix(const vector<vector<int>> &matrix)
{
    vector<int> v;
    for (const auto &row : matrix)
    {
        v.insert(v.end(), row.begin(), row.end());
    }
    sort(v.begin(), v.end());
    return v;
}

void ShiftMatrix(vector<vector<int>> &matrix, int shiftValue, bool shiftRows)
{
    if (shiftRows)
    {
        for (auto &row : matrix)
        {
            rotate(row.begin(), row.begin() + shiftValue, row.end());
        }
    }
    else
    {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        vector<int> temp(numRows);
        for (int j = 0; j < numCols; ++j)
        {
            for (int i = 0; i < numRows; ++i)
            {
                temp[i] = matrix[i][j];
            }
            rotate(temp.begin(), temp.begin() + shiftValue, temp.end());
            for (int i = 0; i < numRows; ++i)
            {
                matrix[i][j] = temp[i];
            }
        }
    }
}

void RemoveRowOrCol(vector<vector<int>> &matrix, int indexToRemove, bool removeRow)
{
    if (removeRow)
    {
        matrix.erase(matrix.begin() + indexToRemove);
    }
    else
    {
        for (auto &row : matrix)
        {
            row.erase(row.begin() + indexToRemove);
        }
    }
}

bool IsPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int CountPrimes(const vector<vector<int>> &matrix)
{
    int count = 0;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            if (IsPrime(val))
                ++count;
        }
    }
    return count;
}

int main()
{
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    vector<vector<int>> matrix;
    int rows, cols;
    ReadDataFromFile(inputFileName, matrix, rows, cols);

    vector<string> outputData;
    vector<int> rowSums = SumRows(matrix);
    for (int i = 0; i < rows; ++i)
    {
        outputData.push_back("Dong " + to_string(i + 1) + ": " + to_string(rowSums[i]));
    }
    vector<int> colSums = SumCols(matrix);
    for (int j = 0; j < cols; ++j)
    {
        outputData.push_back("Cot " + to_string(j + 1) + ": " + to_string(colSums[j]));
    }

    vector<pair<int, int>> MaxMinRow_Kq = MaxMinRows(matrix);
    vector<pair<int, int>> MaxMinCol_kq = MaxMinCols(matrix);
    for (int i = 0; i < MaxMinRow_Kq.size(); i++)
        outputData.push_back("Max of row " + to_string(i + 1) + ": " + to_string(MaxMinRow_Kq[i].first) + " Min of row " + to_string(i + 1) + ": " + to_string(MaxMinRow_Kq[i].second));
    for (int i = 0; i < MaxMinCol_kq.size(); i++)
        outputData.push_back("Max of col " + to_string(i + 1) + ": " + to_string(MaxMinCol_kq[i].first) + " Min of col " + to_string(i + 1) + ": " + to_string(MaxMinCol_kq[i].second));
    pair<int, int> minMax = FindMinMax(matrix);
    outputData.push_back("Lon nhat: " + to_string(minMax.first));
    outputData.push_back("Nho nhat: " + to_string(minMax.second));

    vector<int> sortedMatrix = SortMatrix(matrix);
    outputData.push_back("Sap xep toan bo du lieu theo thu tu tang dan:");
    for (int val : sortedMatrix)
    {
        outputData.push_back(to_string(val));
    }

    ShiftMatrix(matrix, 1, true);
    outputData.push_back("Dich chuyen du lieu theo dong 1 don vi sang phai:");
    for (const auto &row : matrix)
    {
        string rowData;
        for (int val : row)
        {
            rowData += to_string(val) + " ";
        }
        outputData.push_back(rowData);
    }
    RemoveRowOrCol(matrix, 3, false);
    outputData.push_back("Xoa cot thu 4:");
    for (const auto &row : matrix)
    {
        string rowData;
        for (int val : row)
        {
            rowData += to_string(val) + " ";
        }
        outputData.push_back(rowData);
    }

    int primeCount = CountPrimes(matrix);
    outputData.push_back("So luong so nguyen to trong ma tran: " + to_string(primeCount));

    WriteDataToFile(outputFileName, outputData);

    return 0;
}

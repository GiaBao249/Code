#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

void ReadDataFromFile(const string &fileName, int matrix[MAX_SIZE][MAX_SIZE], int &rows, int &cols)
{
    ifstream inputFile(fileName);
    if (!inputFile.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }

    inputFile >> rows >> cols;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();
}

void SumRows(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string outputFile[MAX_SIZE])
{
    outputFile[0] = "Tong dong :";
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
        outputFile[i + 1] = "Dong " + to_string(i + 1) + ":" + to_string(sum);
    }
}

void SumCols(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string outputFile[MAX_SIZE])
{
    outputFile[0] = "Tong cot :";
    for (int i = 0; i < cols; i++)
    {
        int sum = 0;
        for (int j = 0; j < rows; j++)
        {
            sum += matrix[j][i];
        }
        outputFile[i + 1] = "Cot " + to_string(i + 1) + ":" + to_string(sum);
    }
}

void SortFile(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string outputFile[MAX_SIZE * MAX_SIZE])
{
    int res[MAX_SIZE * MAX_SIZE];
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            res[k++] = matrix[i][j];
        }
    }
    sort(res, res + rows * cols);

    outputFile[0] = "Sort tang dan :";
    for (int i = 0; i < rows * cols; i++)
    {
        outputFile[i + 1] = to_string(res[i]);
    }
}

void MaxMinFull(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int &maxVal, int &minVal)
{
    minVal = INT_MAX;
    maxVal = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            minVal = min(minVal, matrix[i][j]);
            maxVal = max(maxVal, matrix[i][j]);
        }
    }
}

void CheoChinh(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int &sum, string &output)
{
    sum = 0;
    output = "Tong tren duong cheo chinh : ";
    for (int i = 0; i < rows; i++)
    {
        sum += matrix[i][i];
    }
    output += to_string(sum);
}

void CheoPhu(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int &sum, string &output)
{
    sum = 0;
    output = "Tong tren duong cheo phu : ";
    for (int i = 0; i < rows; i++)
    {
        sum += matrix[i][cols - i - 1];
    }
    output += to_string(sum);
}

int CountIsPrime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void WriteDataToFile(const string &fileName, const string data[MAX_SIZE], int size)
{
    ofstream outputFile(fileName);
    if (!outputFile.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        outputFile << data[i] << endl;
    }
    outputFile.close();
}

int main()
{
    string inputFileName = "File19.txt";
    string outputFileName = "OutFile19.txt";

    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    string outputFile[MAX_SIZE * MAX_SIZE];

    ReadDataFromFile(inputFileName, matrix, rows, cols);

    SumRows(matrix, rows, cols, outputFile);
    SumCols(matrix, rows, cols, outputFile);

    int maxVal, minVal;
    MaxMinFull(matrix, rows, cols, maxVal, minVal);
    outputFile[2 * cols + 2] = "Max cua matrix :" + to_string(maxVal) + ", Min cua matrix :" + to_string(minVal);

    SortFile(matrix, rows, cols, outputFile);

    int sum;
    CheoChinh(matrix, rows, cols, sum, outputFile[2 * cols + 3]);
    CheoPhu(matrix, rows, cols, sum, outputFile[2 * cols + 4]);

    int countPrimes = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            countPrimes += CountIsPrime(matrix[i][j]);
        }
    }
    outputFile[2 * cols + 5] = "Co tong cong " + to_string(countPrimes) + " so nguyen to";

    WriteDataToFile(outputFileName, outputFile, 2 * cols + 6);

    return 0;
}

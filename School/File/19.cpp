#include <bits/stdc++.h>
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
vector<string> SumRows(vector<vector<int>> &v)
{
    vector<string> res;
    res.push_back("Tong cot :");
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            sum += v[i][j];
        }
        res.push_back("Cot " + to_string(i + 1) + ":" + to_string(sum));
    }
    return res;
}

vector<string> SumCol(vector<vector<int>> &v)
{
    vector<string> res;
    res.push_back("Tong dong :");
    int sum = 0;
    for (int i = 0; i < v[0].size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            sum += v[i][j];
        }
        res.push_back("Dong " + to_string(i + 1) + ":" + to_string(sum));
    }
    return res;
}

vector<int> ResizeMatrix(vector<vector<int>> &v)
{
    vector<int> res;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            res.push_back(v[i][j]);
        }
    }
    return res;
}

vector<string> SortFile(vector<vector<int>> &v)
{
    vector<int> res = ResizeMatrix(v);
    for (int i = 0; i < res.size() - 1; i++)
    {
        for (int j = i + 1; j < res.size(); j++)
        {
            if (res[i] > res[j])
                swap(res[i], res[j]);
        }
    }

    vector<string> ans;
    ans.push_back("Sort tang dan :");
    for (auto it : res)
    {
        ans.push_back(to_string(it));
    }
    return ans;
}

pair<int, int> MaxMinFull(vector<vector<int>> &v)
{
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            minVal = min(minVal, v[i][j]);
            maxVal = max(maxVal, v[i][j]);
        }
    }
    return {maxVal, minVal};
}

vector<pair<int, int>> MaxMinRows(vector<vector<int>> &v)
{
    vector<pair<int, int>> res;
    for (int i = 0; i < v.size(); i++)
    {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
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
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (int j = 0; j < v.size(); j++)
        {
            minVal = min(minVal, v[j][i]);
            maxVal = max(maxVal, v[j][i]);
        }
        res.push_back({maxVal, minVal});
    }
    return res;
}

vector<string> CheoChinh(vector<vector<int>> &v)
{
    int sum = 0;
    vector<string> res;
    res.push_back("Tong tren duong cheo chinh : ");
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i][i];
    }
    res.push_back(to_string(sum));
    return res;
}

vector<string> CheoPhu(vector<vector<int>> &v)
{
    vector<string> res;
    res.push_back("Tong tren duong cheo phu : ");
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i][v.size() - i - 1];
    }
    res.push_back(to_string(sum));
    return res;
}

void RemoveRow(vector<vector<int>> &v, vector<vector<int>> &res, int k)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i != k)
            res.push_back(v[i]);
    }
}

void RemoveCol(vector<vector<int>> &v, vector<vector<int>> &res, int k)
{
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> row;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (j != k)
                row.push_back(v[i][j]);
        }
        res.push_back(row);
    }
}

bool snt(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<string> CountIsPrime(vector<vector<int>> v)
{
    vector<string> res;
    int count = 0;
    for (vector<int> &row : v)
    {
        for (int val : row)
        {
            if (snt(val))
                count++;
        }
    }
    return {"Co tong cong " + to_string(count) + " so nguyen to"};
}

void WriteDataToFile(string &fileName, vector<string> &v)
{
    ofstream outputFile(fileName);
    if (!outputFile.is_open())
    {
        cerr << "Khong mo duoc file." << endl;
        return;
    }
    for (const string &line : v)
    {
        outputFile << line << endl;
    }
    outputFile.close();
}

int main()
{
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    vector<vector<int>> matrix;
    int n, m;
    vector<string> outputFile;
    ReadDataFromFile(inputFileName, matrix, n, m);

    vector<string> sumRow_Kq = SumRows(matrix);
    for (auto row : sumRow_Kq)
    {
        outputFile.push_back(row);
        cout << row << endl;
    }
    vector<string> sumCol_Kq = SumCol(matrix);
    for (auto col : sumCol_Kq)
    {
        outputFile.push_back(col);
        cout << col << endl;
    }

    vector<pair<int, int>> MaxMinRow_Kq = MaxMinRows(matrix);
    for (int i = 0; i < MaxMinRow_Kq.size(); i++)
    {
        outputFile.push_back("Max of row " + to_string(i + 1) + ": " + to_string(MaxMinRow_Kq[i].first) + " Min of row " + to_string(i + 1) + ": " + to_string(MaxMinRow_Kq[i].second));
        cout << MaxMinRow_Kq[i].first << " " << MaxMinRow_Kq[i].second << endl;
    }
    vector<pair<int, int>> MaxMinCol_kq = MaxMinCols(matrix);
    for (int i = 0; i < MaxMinCol_kq.size(); i++)
    {
        outputFile.push_back("Max of col " + to_string(i + 1) + ": " + to_string(MaxMinCol_kq[i].first) + " Min of col " + to_string(i + 1) + ": " + to_string(MaxMinCol_kq[i].second));
        cout << MaxMinCol_kq[i].first << " " << MaxMinCol_kq[i].second << endl;
    }
    pair<int, int> MaxMinFull_kq = MaxMinFull(matrix);
    {
        outputFile.push_back("Max cua matrix :" + to_string(MaxMinFull_kq.first) + ", Min cua matrix :" + to_string(MaxMinFull_kq.second));
        cout << MaxMinFull_kq.first << " " << MaxMinFull_kq.second << endl;
    }

    vector<string> Sorted = SortFile(matrix);
    outputFile.insert(outputFile.end(), Sorted.begin(), Sorted.end());
    for (auto it : Sorted)
        cout << it << endl;

    vector<string> CheoChinh_kq = CheoChinh(matrix);
    outputFile.insert(outputFile.end(), CheoChinh_kq.begin(), CheoChinh_kq.end());
    for (auto it : CheoChinh_kq)
        cout << it << endl;

    vector<string> CheoPhu_kq = CheoPhu(matrix);
    outputFile.insert(outputFile.end(), CheoPhu_kq.begin(), CheoPhu_kq.end());
    for (auto it : CheoPhu_kq)
        cout << it << endl;
    vector<string> countPrimesResult = CountIsPrime(matrix);
    outputFile.insert(outputFile.end(), countPrimesResult.begin(), countPrimesResult.end());
    for (auto it : countPrimesResult)
        cout << it << endl;
    WriteDataToFile(outputFileName, outputFile);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Sinh nhị phân
//  void Try(i)
//  {
//      Thử gán các giá trị có thể cho phần tử x[i]
//      for(int j = <Giá trị 1> .... <Giá Trị n>)
//          Kiểm tra phần tử j xem có thể gán đc cho x[i] hay không?
//              x[i] = j
//              <kiểm tra i xem có phải phần tử cuối cùng của cấu hình hay chưa>?
//                  if(i == n)
//                      <Tìm ra 1 cấu hình>
//                  else
//                      Tiếp tục đi xây dựng với phần tử i + 1
//                      Try(i + 1)
//                  BackTracking
//                  Bỏ ghi nhân giá trị của x[i] = j
//  }

int x[100], daxet[100];

// void permute(string &a, int l, int r)
// {
//     if (l == r)
//         cout << a << endl;
//     else
//     {
//         for (int i = l; i <= r; i++)
//         {
//             swap(a[i], a[l]);
//             permute(a, l + 1, r);
//             swap(a[i], a[l]);
//         }
//     }
// }

// void Sinhnhiphan(int i)
// {
//     for (int j = 'A'; j <= 'B'; j++)
//     {
//         x[i] = j;
//         if (i == n)
//         {
//             // Print();
//             cout << endl;
//         }
//         else
//             Sinhnhiphan(i + 1);
//     }
// }

// void Sinhtohopchapk(int i)
// {
//     for (int j = x[i - 1] + 1; j < n - k + i; j++)
//     {
//         x[i] = j;
//         if (i == n)
//         {
//             // Print();
//             cout << endl;
//         }
//         else
//             Sinhtohopchapk(i + 1);
//     }
// }

// void Daycontongbangk(int i, int pos)
// {
//     for (int j = pos; j <= n; j++)
//     {
//         // x[i] = a[j];
//         //  sum += a[j];
//         if (sum == k)
//         {
//             for (int l = 1; l <= i; l++)
//             {
//                 cout << x[l] << " ";
//             }
//             cout << endl;
//         }
//         else
//             Daycontongbangk(i + 1, j + 1);
//         // sum -= a[j];
//     }
// }

// void Mouse1(int i, int j)
// {
//     if (i == n && j == n)
//         cout << s << " ";
//     // Gán nước đi đầu tiên của con chuột khi đang ở vị trí (i , j)
//     if (i + 1 <= n && a[i + 1][j] == 1) // Kiểm tra i + 1 có đang ở trong mảng hay không và vị trí ở dưới (Down) có thể đi đc hay không?
//     {
//         s += "D";
//         a[i + 1][j] = 0;
//         Mouse1(i + 1, j);
//         s.pop_back();    // Xóa nước đi cuối cùng của con chuột
//         a[i + 1][j] = 1; // Reset lai vị trí đó để round sau có thể quay trở lại nếu cụt đường
//     }
//     if (j + 1 <= n && a[i][j + 1] == 1)
//     {
//         s += "R";
//         a[i][j + 1] = 0;
//         Mouse1(i, j + 1);
//         s.pop_back();
//         a[i][j + 1] = 1;
//     }
// }

// void Mouse2(int i, int j)
// {
//     int ok;
//     // Điều kiện dừng
//     if (i == n && j == n)
//     {
//         cout << s << endl;
//         ok = 1;
//     }
//     if (i + 1 <= n && a[i + 1][j] == 1)
//     {
//         s += "D";
//         a[i + 1][j] = 0;
//         Mouse2(i + 1, j);
//         s.pop_back();
//         a[i + 1][j] = 1;
//     }
//     if (j + 1 <= n && a[i][j + 1] == 1)
//     {
//         s += "R";
//         a[i][j + 1] = 0;
//         Mouse2(i, j + 1);
//         s.pop_back();
//         a[i][j + 1] = 1;
//     }
//     if (j - 1 <= n && a[i][j - 1] == 1)
//     {
//         s += "L";
//         a[i][j - 1] = 0;
//         Mouse2(i, j - 1);
//         s.pop_back();
//         a[i][j - 1] = 1;
//     }
//     if (i - 1 <= n && a[i - 1][j] == 1)
//     {
//         s += "U";
//         a[i - 1][j] = 0;
//         Mouse2(i - 1, j);
//         s.pop_back();
//         a[i - 1][j] = 1;
//     }
//     if (ok == 0)
//         cout << "-1" << endl;
// }
// // DLRU
// string path = "DLRU";
// int dx[4] = {1, 0, 0, -1};
// int dy[4] = {0, -1, 1, 0};

// void Mouse2Update(int i, int j)
// {
//     if (i == n && j == n)
//         cout << s << " ";
//     for (int k = 0; k < 4; k++)
//     {
//         int i1 = i + dx[k];
//         int j1 = j + dy[k];
//         if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1)
//         {
//             s += path[k];
//             a[i1][j1] = 0;
//             Mouse2Update(i1, j1);
//             a[i1][j1] = 1;
//             s.pop_back();
//         }
//     }
// }

// void Demvungmien(int i, int j)
// {
//     a[i][j] = 0;
//     for (int k = 0; k < 4; k++)
//     {
//         int i1 = i + dx[k];
//         int j1 = j + dy[k];
//         if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1)
//         {
//             Demvungmien(i1, j1);
//         }
//     }
// }

// void Input()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
// }

char a[100][100];
int ax[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ay[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int k, sum, n, m;
string s;
set<string> dict;
bool check[100][100];
vector<string> res;

void InputDict()
{
    cin >> k >> n >> m;
    for (int i = 0; i < k; i++)
    {
        string word;
        cin >> word;
        dict.insert(word);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    memset(check, 0, sizeof(check));
}

void Dict(int i, int j)
{
    if (dict.count(s))
        res.push_back(s);
    for (int l = 0; l < 8; l++)
    {
        int i1 = i + ax[l];
        int j1 = j + ay[l];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && check[i1][j1] == 0)
        {
            s += a[i1][j1];
            check[i1][j1] = 1;
            Dict(i1, j1);
            check[i1][j1] = 0;
            s.pop_back();
        }
    }
}

int cot[100], d1[100], d2[100], v[100][100];

void ktao()
{
    memset(cot, 0, sizeof(cot));
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
}

void inKq()
{
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; i++)
    {
        v[i][x[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Queen(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] == 0 && d1[i - j + n] == 0 && d2[i + j - 1] == 0)
        {
            x[i] = j;
            cot[j] = 1;
            d1[i - j + n] = 1;
            d2[i + j - 1] = 1;
            if (i == n)
                inKq();
            else
                Queen(i + 1);
            cot[j] = 0;
            d1[i - j + n] = 0;
            d2[i + j - 1] = 0;
        }
    }
}
int main()
{
    ktao();
    cin >> n;
    Queen(1);
}

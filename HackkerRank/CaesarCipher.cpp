#include <bits/stdc++.h>

using namespace std;

string caesarCipher(string s, int k)
{
    int n = s.size();
    string res = "";
    for (int i = 0; i < n; i++)
    {
        char c = s[i] + k;
        if (isalpha(s[i]))
        {
            if (islower(s[i]) && c > 'z')
                res.push_back('a' + (c - 'z' - 1) % 26);
            else if (isupper(s[i]) && c > 'Z')
                res.push_back('A' + (c - 'Z' - 1) % 26);
            else
                res.push_back(c);
        }
        else
            res.push_back(s[i]);
    }
    return res;
}
// string caesarCipher(string s, int k)
// {
//     int n = s.size();
//     string res = "";
//     for (int i = 0; i < n; i++)
//     {
//         char c = s[i];
//         if (isalpha(c))
//         {                                       // Kiểm tra xem ký tự có phải là một ký tự chữ cái không
//             char base = isupper(c) ? 'A' : 'a'; // Xác định điểm bắt đầu của bảng chữ cái
//             c = base + (c - base + k) % 26;     // Áp dụng phép dịch chuyển Caesar, sử dụng % 26 để quay lại vị trí đầu nếu vượt quá
//         }
//         res.push_back(c);
//     }
//     return res;
// }

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << caesarCipher(s, k);

    return 0;
}

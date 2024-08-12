#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "Task";
const string NAME2 = "Submit";
// Số test kiểm tra
const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h)
{
    assert(l <= h);
    return l + abs(rd() * 1LL * rd()) % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        // Code phần sinh test ở đây
        int n = Rand(5, 50) + 1;
        inp << n;
        inp << endl;
        for (int i = 0; i < n; i++)
        {
            int x = Rand(1, 200) + 1;
            inp << x;
            inp << '\n';
        }

        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME2 + ".exe").c_str());
        system((NAME2 + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define For(i ,a ,b) for(int i = a ; i < b ; i++)
#define all(x) x.begin() , x.end()
void Solve()
{
    int a ,b ,c;
    cin >> a >> b >> c;
    bool ok = false;
    set<int> se;
    For(x , -100 , 101)
    {
        For(y , x + 1 , 101)
        {
            ll z = a - x - y;
            if(x + y + z == a && x * y * z == b && x * x + y * y + z * z == c)
            {
                ok = true;
                //cout << x << " " << y << " " << z << endl;
                se.insert(x) , se.insert(y) , se.insert(z);
            }
        }
    }
    if(!ok)
        cout << "No solution." << endl;
    else
    {
        for(auto x : se)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        Solve();
    }
}

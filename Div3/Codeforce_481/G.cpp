///Ever try ever failed no matter , try again fail again fail better!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define Rep(i, a, b) for (ll i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)x.size()
#define el '\n'
#define inf INT_MAX
const ll N = 105;
const ll MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
struct Node {
    int s, d, c;
};

vector<Node> q;
bool cmp(int a , int b)
{
    return q[a].d < q[b].d;
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    q.resize(m);
    vector<int> res(n);
    f0(i, m) {
        cin >> q[i].s >> q[i].d >> q[i].c;
        q[i].s--, q[i].d--;
        res[q[i].d] = m + 1;
    }
    vector<int> day(m);
    f0(i , m){
        day[i] = i;
    }
    sort(all(day), cmp);
    f0(i, m) {
        Node p = q[day[i]];
        int c = p.s;
        For(j, 0, p.c) {
            while(c < p.d && res[c] != 0) {
                c++;
            }
            if(c == p.d) {
                cout << -1 << el;
                return;
            }
            res[c] = day[i] + 1;
        }
    }
    for(int i = 0 ; i < n ; i++) {
        cout << res[i] << ' ';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}


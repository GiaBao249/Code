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
const ll N = 4e5 + 5;
const ll MOD = 1e9 + 7;

ll t[104], f[26];
int n, k;
string s ;
queue<int> pos[26];
void build(int id, int l, int r)
{
    if(l == r) {
        t[id] = f[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

void update(int id, int l, int r, int p, int v)
{
    if(p < l || p > r) {
        return;
    }
    if(l == r) {
        t[id] = v;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, p, v);
    update(id << 1 | 1, mid + 1, r, p, v);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

ll get(int id, int l, int r, int u)
{
    if(l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    if(t[id << 1] >= u) {
        return get(id << 1, l, mid, u);
    }
    return get(id << 1 | 1, mid + 1, r, u - t[id << 1]);
}

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}
void Solve()
{
    cin >> n >> k >> s;
    for(int i = 0 ; i < sz(s) ; i++){
        f[s[i] - 'a']++;
        pos[s[i] - 'a'].push(i);
    }
    build(1 , 0 , 25);
    int cnt = 0;
    f0(i , k){
        int idx = get(1 , 0 , 25 , 1);
        char ch = 'a' + idx;
        int j = pos[idx].front();
        pos[idx].pop();
        s[j] = '_';
        f[idx]--;
        update(1 , 0 ,25 , idx , f[idx]);
    }
    string rs ;
    for(auto c : s){
        if(c != '_'){
            rs += c;
        }
    }
    cout << rs << el;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //file();
    Solve();
    return 0;
}



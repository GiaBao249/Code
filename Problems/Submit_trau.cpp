//Ever try ever failed no matter , try again fail again fail better!
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
#define MAX INT_MAX
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;

struct Node{
    int id;
    ll depth;
    Node *par;
    Node *jump;
};
vector<int> a[N];
Node *t[N];

void dfs(int u){
    for(int v : a[u]){
        Node *newNode = new Node();
        newNode->depth = t[u]->depth + 1;
        newNode->par = t[u];
        newNode->id = v;
        if(t[u]->depth - t[u]->jump->depth == t[u]->jump->depth - t[u]->jump->jump->depth){
            newNode->jump = t[u]->jump->jump;
        }else{
            newNode->jump = t[u];
        }
        t[v] = newNode;
        dfs(v);
    }
}


void file() {
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

int find(Node *u , int d){
    while(u->depth > d){
        if(u->jump->depth < d){
            u = u->par;
        }else{
            u = u->jump;
        }
    }
    return u->id;
}

void Solve() {
    int n , q;
    cin >> n >> q;

    for(int i = 2 ; i <= n ; i++){
        int x ;  cin >> x;
        a[x].pb(i);
    }
    Node *newNode = new Node();
    t[1]->par = NULL;
    t[1]->jump = newNode;
    t[1]->depth = 0;
    t[1]->id = 1;
    dfs(1);
    while(q--){
        int x , k;
        cin >> x >> k;
//        if(k > t[x]->depth){
//            cout << -1 << el;
//            return;
//        }
        //cout << find(t[x], t[x]->depth - k) << el;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //file();
    Solve();
    return 0;
}

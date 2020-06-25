#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////
const int N = 1e6+1;
int n, k, par[N], d[N], rd[N], used[N], t[2 * N];
vector<int> g[N];
set<int> ans;

void build() {  // build the tree
    REP(i, n) t[i+n] = 0;
    FORD(i, n-1, 0) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
    --p;
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
    --l;
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(res, t[--r]);
    }
    return res;
}

void dfs(int s) {
    rd[s] = d[s] - query(s, n+1);
    // DEBUG(s);
    // DEBUG(par[s]);
    // DEBUG(rd[s]);
    modify(s, d[s]);
    for(int v : g[s]) {
        if(v != par[s]) {
            par[v] = s;
            d[v] = d[s]+1;
            dfs(v);
        }
    }
    modify(s, 0);
}

void use(int s) {
    if(s == -1 || used[s]) return;
    // DEBUG(s);
    ans.erase(s);
    used[s] = 1;
    use(par[s]);
}

void print() {
    FORD(i, n, 1) cout << i << ' ' << rd[i] << ' ' << used[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    fill(par, par+N, -1);
    fill(used, used+N, 0);
    build();
    cin >> n >> k;
    REP(i, n-1){
        int s, e;
        cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }
    d[n] = 0;
    dfs(n);
    rd[n] = 1;
    k = n-k;
    DEBUG(k);
    FOR(i, 1, n) ans.insert(i);
    FORD(i, n, 1) {
        if(!used[i] && rd[i] <= k) {
            // DEBUG(i);
            k -= rd[i];
            use(i);
            print();
            DEBUG(k);
        }
    }
    for(int i : ans) cout << i << ' ';
    cout << endl;

    return 0;
}
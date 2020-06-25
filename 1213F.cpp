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
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// #define int long long
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
const int N = 2e5+10;
vector<int> scc[N], g[N], rg[N], sccg[N];
int n, sccn[N];
bool vis[N];
stack<int> verts;

void dfs(int s) {
    vis[s] = 1;
    for(int v : g[s]) if(!vis[v]) dfs(v);
    verts.push(s);
}

void dfs2(int s, vector<vector<int>>& rg, int scn) {
    vis[s] = 1;
    scc[scn].push_back(s);
    for(int v : rg[s]) if(!vis[v]) dfs2(v, rg, scn);
}

void build_rg() {
	FOR(i, 1, n) for(int v : g[i]) rg[v].push_back(i);
}

void find_scc() {
	build_rg();
    FOR(i, 1, n) if(!vis[i]) dfs(i);
    memset(vis, 0, sizeof(vis));
    
    while(!verts.empty()) {
        if(!vis[verts.top()]) {
            int scn = scc.size();
            scc.resize(scn+1);
            dfs2(verts.top(), rg, scn);
        }
        verts.pop();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)


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

const int N = 2e5+1;
int n, c[N], nc[N], a[N], scn, sccs[N], d[N];
vector<int> g[N], sccg[N];

vector<vector<int>> scc;
vector<bool> vis;
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

void findSCC() {
    vis.resize(n+1, 0);
    FOR(i, 1, n) if(!vis[i]) dfs(i);

    vector<vector<int>> rg(n+1);
    FOR(i, 1, n) for(int v : g[i]) rg[v].push_back(i);
    fill(vis.begin(), vis.end(), 0);
    
    while(!verts.empty()) {
        if(!vis[verts.top()]) {
            scn = scc.size();
            scc.resize(scn+1);
            dfs2(verts.top(), rg, scn);
        }
        verts.pop();
    }
    ++scn;

    REP(i, scn) REP(j, scc[i].size()) sccs[scc[i][j]] = i;
}

void buildsccg() {
	REP(i, scn) {
		vector<int> to;
		for(int v : scc[i]) {
			// DEBUG(v);
			for(int dest : g[v]) {
				// DEBUG(dest);
				if(sccs[dest] != i) to.push_back(sccs[dest]);
			}
		}
		// DEBUG(to.size());
		sort(to.begin(), to.end());
		// REP(j, to.size()) cout << to[j] << ' ';
		// cout << endl;
		REP(j, (int)to.size() - 1) {
			if(to[j] != to[j+1]) sccg[i].push_back(to[j]);
		}
		if(to.size() && (to.size() < 2 || to[to.size()-2] != to[to.size()-1])) sccg[i].push_back(to[to.size()-1]);

		// REP(j, sccg[i].size()) cout << sccg[i][j] << ' ';
		// cout << endl;

		nc[i] = INF;
		for(int v : scc[i]) {
			// DEBUG(v);
			// DEBUG(c[v]);
			nc[i] = min(nc[i], c[v]);
		}
	}
}

int topodfs(int s) {
	DEBUG(s);
	int cur = 0;
	for(int v : sccg[s]) {
		cur += topodfs(v);
	}
	int res = sccg[s].size() ? min(cur, nc[s]) : nc[s];
	DEBUG(res);
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) g[a[i]].push_back(i);
    // DEBUG("here1");
    findSCC();
    // DEBUG("here2");
    buildsccg();
    // DEBUG("here3");
    memset(d, 0, sizeof(d));
    REP(i, scn) {
    	for(int v : sccg[i]) {
    		++d[v];
    	}
    }
    // REP(i, scn) {
    // 	for(int v : scc[i]) cout << v << ' ';
    // 	cout << endl;
    // }
    // cout << endl;
    // REP(i, scn) {
    // 	for(int v : sccg[i]) cout << v << ' ';
    // 	cout << endl;
    // }
    // cout << endl;
    // REP(i, scn) {
    // 	cout << d[i] << ' ';
    // }
    // cout << endl;
    // DEBUG("here4");
    int ans = 0;
    REP(i, scn) {
    	if(d[i] == 0) ans += nc[i];
    }
    cout << ans << endl;

    return 0;
}
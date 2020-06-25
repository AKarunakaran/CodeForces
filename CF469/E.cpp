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
const int INF = 0x3f3f3f3f;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

int n, m, h;
vector<int> u, sccs, sccid;
vector<vector<int>> scc, g, sccg;
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
            int scn = scc.size();
            scc.resize(scn+1);
            dfs2(verts.top(), rg, scn);
        }
        verts.pop();
    }
}

bool dfs3(int s, int scn) {
	if(sccid[s] != scn) return false;
	vis[s] = 1;
	for(int v : g[s]) {
		if(!vis[v]) {
			if(!dfs3(v, scn)) return false;
		}
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> h;
    u.resize(n+1);
    vis.resize(n+1, 0);
    g.resize(n+1);
    REP(i, n) cin >> u[i+1];
    set<pii> edges;
    REP(i, m) {
    	int s, e;
    	cin >> s >> e;
    	edges.insert({s, e});
    }
    for(pii p : edges) {
    	int s = p.first, e = p.second;
    	if((u[s]+1)%h == u[e]) g[s].push_back(e);
    	if((u[e]+1)%h == u[s]) g[e].push_back(s);
    }
    findSCC();
    int scn = scc.size();
    sccid.resize(n+1);
    REP(i, scn) {
    	REP(j, scc[i].size()) {
    		sccid[scc[i][j]] = i;
    	}
    }
    sccs.resize(scn);
    sccg.resize(scn);
    fill(vis.begin(), vis.end(), 0);
    int ans = INF, ansi = -1;
    REP(i, scn) {
    	if(dfs3(scc[i][0], i)) {
    		// DEBUG(i);
    		// DEBUG(scc[i][0]);
    		if(scc[i].size() < ans) {
    			ans = scc[i].size();
    			ansi = i;
    		}
    	}
    }

    cout << ans << endl;
    REP(i, scc[ansi].size()) cout << scc[ansi][i] << ' ';
    cout << endl;

    return 0;
}
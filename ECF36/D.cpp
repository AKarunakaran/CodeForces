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

int n, m;
vector<vector<int>> g;
vector<int> cyclePath;
vector<bool> vis, onPath;

bool dfs(int s) {
	vis[s] = 1;
	onPath[s] = 1;
	for(int v : g[s]) {
		cyclePath.push_back(v);
		if(onPath[v]) {
			return true;
		} else if(!vis[v]) {
			if(dfs(v)) return true;
		}
		cyclePath.pop_back();
	}
	onPath[s] = 0;
	return false;
}

bool dfs2(int s, int from, int to) {
	vis[s] = 1;
	onPath[s] = 1;
	for(int v : g[s]) {
		if(s == from && v == to) continue;
		if(onPath[v]) {
			// DEBUG(s);
			// DEBUG(v);
			return true;
		} else if(!vis[v]) {
			if(dfs2(v, from, to)) return true;
		}
	}
	onPath[s] = 0;
	return false;
}

bool cyclic(int u, int v) {
	fill(vis.begin(), vis.end(), 0);
	fill(onPath.begin(), onPath.end(), 0);
	bool cyc = false;
	FOR(i, 1, n) {
		if(!vis[i]) {
			// DEBUG(i);
			cyc |= dfs2(i, u, v);
		}
		if(cyc) return true;
	}
	return false;
}

int main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1, 0);
    onPath.resize(n+1, 0);
    REP(i, m) {
    	int s, e;
    	cin >> s >> e;
    	g[s].push_back(e);
    }
    bool cyc = false;
    FOR(i, 1, n) {
    	if(!vis[i]) {
    		cyclePath.push_back(i);
    		cyc |= dfs(i);
    		if(!cyc) cyclePath.pop_back();
    	}
    	if(cyc) break;
    }
    if(cyc) {
        int len = cyclePath.size();
        // REP(i, len) cout << cyclePath[i] << ' ';
        // cout << endl;
        REP(i, len-1) {
        	// cout << cyclePath[i] << " ";
        	if(!cyclic(cyclePath[i], cyclePath[i+1])) {
        		cout << "YES" << endl;
        		exit(0);
        	}
        	// cout << endl;
        }
        cout << "NO" << endl;
    } else {
    	cout << "YES" << endl;
    }

    return 0;
}
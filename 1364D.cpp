#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int msbp(int x) {return 31-__builtin_clz(x);}
inline int msb(int x) {return 1 << msbp(x);}
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;

int n, m, k, vis[N], on_path[N];
vector<int> g[N], path, levels[2];

void answer(int ans) {
	cout << ans << endl;
	if(ans == 1) {
		for(int i = 0, j = 0; j < (k+1)/2; i += 2, ++j) {
			cout << path[i] << ' ';
		}
		cout << endl;
	} else {
		cout << path.size() << endl;
		for(int v : path) cout << v << ' ';
		cout << endl;
	}
	exit(0);
}

void cycle() {
	// path is a cycle, now solve problem
	int l = path.size();
	if(l <= k) answer(2);
	// for(int v : path) cout << v << ' ';
	// cout << endl;

	map<int, int> ids;
	REP(i, l) ids[path[i]] = i;
	REP(i, l) {
		int cur = path[i];
		int nxt = path[(i+1)%l];
		int pre = path[(i+l-1)%l];
		// DEBUG(cur);
		// DEBUG(nxt);
		// DEBUG(pre);
		for(int v : g[cur]) {
			if(v == nxt || v == pre) continue;
			if(ids.count(v)) {
				// found sub cycle
				int id = ids[v];
				// DEBUG(path[i]);
				// DEBUG(path[id]);
				// id > i guaranteed
				int d1 = id-i+1;
				int d2 = l+2-d1;
				vector<int> nxt_path;
				if(d1 < d2) {
					// go forward
					FOR(j, i, id) nxt_path.push_back(path[j]);
				} else {
					// go backward
					FOR(j, id, l-1) nxt_path.push_back(path[j]);
					FOR(j, 0, i) nxt_path.push_back(path[j]);
				}
				path = nxt_path;
				cycle();
			}
		}
	}
	answer(1);
}

void dfs(int s, int p = 0, int d = 0) {
	levels[d & 1].push_back(s);
	path.push_back(s);
	vis[s] = on_path[s] = 1;
	for(int v : g[s]) {
		if(v == p) continue;
		if(on_path[v]) {
			int id = -1;
			REP(i, path.size()) {
				if(v == path[i]) {
					id = i;
					break;
				}
			}
			assert(id != -1);
			vector<int> nxt_path;
			FOR(i, id, path.size()-1) nxt_path.push_back(path[i]);
			path = nxt_path;
			cycle();
		}
		if(!vis[v]) dfs(v, s, d+1);
	}
	on_path[s] = 0;
	path.pop_back();
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> k;
    REP(i, m) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1);
    REP(i, 2) {
    	if(levels[i].size() >= (k+1)/2) {
    		path.clear();
    		for(int v : levels[i]) {
    			path.push_back(v);
    			path.push_back(0);
    		}
    		answer(1);
    	}
    }

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
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
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)

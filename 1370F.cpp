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

const int N = 1e3+10;

int t, n, sz[N], subtree[N], parent[N], r, len;
vector<int> g[N], depth[N];

void answer(int u, int v) {
	string res;
	cout << "! " << u << ' ' << v << endl;
	cin >> res;
	if(res == "Incorrect") exit(0);
}

// x, d
pii query(vector<int> v) {
	pii res;
	cout << "? " << v.size() << ' ';
	for(int x : v) cout << x << ' ';
	cout << endl;
	cin >> res.first >> res.second;
	return res;
}

int dfs(int s, int p = 0, int d = 0, int sub = 0) {
	depth[d].push_back(s);
	parent[s] = p;
	subtree[s] = sub;
	sz[s] = 1;
	for(int v : g[s]) {
		if(v == p) continue;
		sz[s] += dfs(v, s, d+1, sub == 0 ? v : sub);
	}
	return sz[s];
}

pii query_layer(int layer) {
	vector<int> q;
	for(int v : depth[layer]) {
		q.push_back(v);
	}
	return query(q);
}

// return true iff layer queries to same result
bool check(int layer, map<int, pii>& m) {
	m[layer] = query_layer(layer);
	return m[layer].second == len;
}

void solve() {
	// 1 query for everything, 9 to find one of the nodes (exclude largest subtree), 1 to find other node

	vector<int> v(n);
	iota(v.begin(), v.end(), 1);
	tie(r, len) = query(v);

	dfs(r);
	map<int, pii> m; // map layer to query result
	int lo = 0, hi = len;
	while(lo < hi) {
		int mid = (lo+hi+1)/2;
		if(depth[mid].empty()) hi = mid-1;
		else if(check(mid, m)) lo = mid;
		else {
			int diff = (m[mid].second-len)/2;
			if(mid-diff > lo) {
				int cur = m[mid].first;
				REP(i, diff) cur = parent[cur];
				lo = mid-diff;
			}
			hi = mid-1;
		}
	}
	m[0] = {r, len};
	if(m[lo].first == 0) m[lo] = query_layer(lo, banned);
	// DEBUG(m[lo].first);
	// DEBUG(subtree[m[lo].first]);
	auto oth = query_layer(len-lo, subtree[m[lo].first]);

	answer(m[lo].first, oth.first);
}

void reset() {
	memset(sz, 0, sizeof(sz));
	memset(subtree, 0, sizeof(subtree));
	memset(parent, 0, sizeof(parent));
	FOR(i, 0, n) {
		g[i].clear();
		depth[i].clear();
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n;
    	reset();
    	REP(i, n-1) {
    		int u, v;
    		cin >> u >> v;
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	solve();
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
// - negative arithmetic, ceiling division, modulo (WA)
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

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
// const int INF = 0x3f3f3f3f;
const int INF = INT_MAX;
// const int nINF = INT_MIN;

/////////////////////////////////////////////////////////////////////

// LCA using binary lifting
// Preprocess with lcadfs(root), and find lca of u, v with lca(u, v)
// O(n log n) preprocessing, O(log n) query
const int N = 1e5+10;
int ts[N], te[N], lcat = 0, dep[N];
vector<int> g[N], ba[N];

void lcadfs(int s, int p = 0, int d = 0) {
	dep[s] = d;
	ts[s] = lcat++;
	ba[s].push_back(p);
	for(int i = 1; d - (1 << i) >= 0; ++i)
		ba[s].push_back(ba[ba[s][i-1]][i-1]);

	for(int v : g[s])
		if(v != p)
			lcadfs(v, s, d+1);
	te[s] = lcat++;
}

bool anc(int u, int v) {return ts[u] <= ts[v] && te[u] >= te[v];}

int lca(int u, int v) {
	if(anc(u, v)) return u;
	if(anc(v, u)) return v;
	int l = ba[u].size()-1;
	FORD(i, l, 0) {
		if(i < ba[u].size() && !anc(ba[u][i], v))
			u = ba[u][i];
	}
	return ba[u][0];
}

int dist(int u, int v) {
	return dep[u]+dep[v]-2*dep[lca(u, v)];
}

int n, q, x, y, a, b, k;

int find_shortest_dist(int par) {
	int res = INF;
	int dis = dist(a, b);
	if((dis & 1) == par) res = min(res, dis);
	int try1 = dist(a, x) + 1 + dist(y, b);
	int try2 = dist(a, y) + 1 + dist(x, b);
	if((try1 & 1) == par) res = min(res, try1);
	if((try2 & 1) == par) res = min(res, try2);
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    REP(i, n-1) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    lcadfs(1);
    cin >> q;
    REP(i, q) {
    	cin >> x >> y >> a >> b >> k;
    	int shortest = find_shortest_dist(k & 1);
    	// DEBUG(shortest);
    	cout << (shortest <= k ? "YES" : "NO") << endl;
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

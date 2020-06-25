#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
typedef long long ll;
typedef pair<int, int> pii;
// const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
// const int nINF = 1<<31;
#define int long long

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10; // Upper bound for n

int parent[N];
int sz[N];

// Uses path compression
int find(int x) {return parent[x] = (x == parent[x] ? x : find(parent[x]));}

bool disjoint(int x, int y) {return find(x) != find(y);}

void join(int x, int y) {
	if (!disjoint(x, y)) return;
	int newPar = find(x), newChild = find(y);
	sz[newPar] += sz[newChild];
	parent[newChild] = newPar;
}

int dsuSize(int x) {return sz[find(x)];}

int n, m, k, q, d[N], answers[3*N];
vector<pii> g[N], qlist;
vector<int> components[N];
unordered_set<int> queries[N];
map<pii, int> query_answers;
vector<pair<int, pii>> edges;

void dijkstra() {
	set<pii> nxt;
	memset(d, INF, sizeof(d));
	FOR(i, 1, k) {
		d[i] = 0;
		nxt.insert({0, i});
	}
	while(!nxt.empty()) {
		int cur = nxt.begin()->second;
		nxt.erase(nxt.begin());
		for(auto&[v, w] : g[cur]) {
			if(d[cur]+w < d[v]) {
				nxt.erase({d[v], v});
				d[v] = d[cur]+w;
				nxt.insert({d[v], v});
			}
		}
	}
}

void answer_and_merge(int u, int v, int ans) {
	// cout << u << ' ' << v << endl;
	vector<int>& smaller = components[u];
	vector<int>& larger = components[v];
	for(int x : smaller) {
		// cout << "smaller component vertex " << x << endl;
		auto& curq = queries[x];
		vector<int> to_delete;
		for(int oth : curq) {
			// cout << "query " << x << ' ' << oth << endl;
			if(find(oth) == v) {
				if(!query_answers.count({x, oth})) {
					// cout << x << ' ' << oth << "  " << ans << endl;
					query_answers[{x, oth}] = query_answers[{oth, x}] = ans;
				}
				to_delete.push_back(oth);
			}
		}
		for(int oth : to_delete)
			curq.erase(oth);
		larger.push_back(x);
	}
	smaller.clear();
	join(v, u);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    std::iota(parent, parent+N, 0), std::fill(sz, sz+N, 1);
    cin >> n >> m >> k >> q;
    FOR(i, 1, n) components[i].push_back(i);
    REP(_, m) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }
    REP(i, q) {
    	int a, b;
    	cin >> a >> b;
    	queries[a].insert(b);
    	queries[b].insert(a);
    	qlist.push_back({a, b});
    }
    dijkstra();
    FOR(i, 1, n)
    	for(auto&[v, w] : g[i])
    		edges.push_back({w+d[v]+d[i], {i, v}});
    sort(edges.begin(), edges.end());
    REP(i, edges.size()) {
    	int e = edges[i].first;
    	int u = find(edges[i].second.first), v = find(edges[i].second.second);
    	if(disjoint(u, v)) {
    		// cout << u << ' ' << v << "  " << e << endl;
    		if(dsuSize(u) > dsuSize(v)) swap(u, v);
    		answer_and_merge(u, v, e);
    	}
    }
    // FOR(i, 1, n) cout << find(i) << ' ';
    // cout << endl;
    REP(i, q) cout << query_answers[qlist[i]] << endl;

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
// - forgetting to rename recursive call when copy/pasting recursive function (WA)

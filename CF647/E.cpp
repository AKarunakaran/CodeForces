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

////////////////////////////////////////////////////////////////////

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5+10;

int t, n, m, on_path[N], vis[N], depends_on[N], good[N];
vector<int> g[N], interesting, to_remove[N];
set<int> ancestors[N];

bool dfs(int s) {
	vis[s] = on_path[s] = 1;
	for(int v : g[s]) {
		if((vis[v] && !on_path[v]) || (!vis[v] && !dfs(v))) {
			return false;
		}
	}
	on_path[s] = 0;
	return true;
}

void merge(set<int>& a, set<int>& b) {
	if(a.size() < b.size()) a.swap(b);
	for(int x : b) a.insert(x);
	b.clear();
}

int dfs2(int s) {
	auto& cur = ancestors[s];
	int going_up = 0;
	vis[s] = 1;
	for(int v : g[s]) {
		if(vis[v]) {
			to_remove[v].push_back(s);
			cur.insert(v);
			++going_up;
		} else {
			going_up += dfs2(v);
			auto& child = ancestors[v];
			merge(cur, child);
		}
	}
	going_up -= to_remove[s].size();
	for(int v : to_remove[s])
		cur.erase(s);

	to_remove[s].clear();
	if(going_up == 1) {
		depends_on[s] = *cur.begin();
	} else if(going_up > 1) {
		good[s] = 0;
	}
	return going_up;
}

void dfs3(int s) {
	vis[s] = 1;
	if(good[s] == -1) {
		good[s] = good[depends_on[s]];
	}
	for(int v : g[s])
		if(!vis[v])
			dfs3(v);
}

void get_interesting(int root) {
	memset(vis, 0, sizeof(vis));
	memset(good, -1, sizeof(good));
	dfs2(root);
	ancestors[root].clear();

	good[root] = 1;
	memset(vis, 0, sizeof(vis));
	dfs3(root);
	FOR(i, 1, n) if(good[i] == 1) interesting.push_back(i);
}

void solve() {
	vector<int> order(n);
	iota(order.begin(), order.end(), 1);
	shuffle(order.begin(), order.end(), rng);
	int trials = min(n, 100);
	int good = -1;
	REP(i, trials) {
		int cur = order[i];
		memset(vis, 0, sizeof(vis));
		if(dfs(cur)) {
			good = cur;
			break;
		}
	}
	if(good == -1) {
		cout << -1 << endl;
		return;
	}
	get_interesting(good);
	if(interesting.size()*5 < n) {
		cout << -1 << endl;
	} else {
		sort(interesting.begin(), interesting.end());
		for(int v : interesting) cout << v << ' ';
		cout << endl;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    srand(time(NULL));
    cin >> t;
    while(t--) {
    	interesting.clear();
    	cin >> n >> m;
    	FOR(i, 1, n) g[i].clear();
    	REP(i, m) {
    		int a, b;
    		cin >> a >> b;
    		g[a].push_back(b);
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

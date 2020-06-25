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
const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10;

int n, q, qn[N], qc[N], qg[N];
vector<int> g[N], qs[N];

void add_vertex(int v) {
	for(int query : qs[v]) {
		++qc[query];
		if(qc[query] == qn[query]) qg[query] = 1;
	}
}

void remove_vertex(int v) {
	for(int query : qs[v]) --qc[query];
}

void dfs(int s, int p = -1) {
	for(int v : g[s]) if(v != p) add_vertex(v);
	for(int v : g[s]) if(v != p) dfs(v, s);
	for(int v : g[s]) if(v != p) remove_vertex(v);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> q;
    REP(_, n-1) {
    	int a, b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }
    REP(i, q) {
    	cin >> qn[i];
    	REP(j, qn[i]) {
    		int v;
    		cin >> v;
    		qs[v].push_back(i);
    	}
    }
    add_vertex(1);
    dfs(1);
    REP(i, q) cout << (qg[i] ? "YES" : "NO") << endl;

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

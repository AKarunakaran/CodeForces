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

const int N = 2e5+10;

int b[N], c[N], n, change[2];
ll a[N], ans;
vector<int> g[N];

void reduce_cost(int s, int p = 0) {
	for(int v : g[s]) {
		if(v != p) {
			a[v] = min(a[v], a[s]);
			reduce_cost(v, s);
		}
	}
}

pii dfs(int s, int p = 0) {
	pii cur{0, 0};
	if(b[s] == 0 && c[s] == 1) cur.first++;
	if(b[s] == 1 && c[s] == 0) cur.second++;
	for(int v : g[s]) {
		if(v != p) {
			pii res = dfs(v, s);
			cur.first += res.first, cur.second += res.second;
		}
	}
	int changes = min(cur.first, cur.second);
	ans += 2*changes*a[s];
	cur.first -= changes, cur.second -= changes;
	return cur;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    FOR(i, 1, n) {
    	cin >> a[i] >> b[i] >> c[i];
    	REP(j, 2) if(b[i] == j && c[i] == 1-j) ++change[j];
    }
    if(change[0] != change[1]) {
    	cout << -1 << endl;
    	exit(0);
    }
    REP(i, n-1) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    reduce_cost(1);
    dfs(1);
    cout << ans << endl;

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

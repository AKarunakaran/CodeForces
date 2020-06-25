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

int t, n, m, close[N], ans;
vector<int> g[N], rg[N];

void reset() {
	FOR(i, 1, n) {
		rg[i].clear();
		g[i].clear();
		close[i] = 0;
	}
	ans = 0;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> n >> m;
    	reset();
    	REP(i, m) {
    		int u, v;
    		cin >> u >> v;
    		g[u].push_back(v);
    		rg[v].push_back(u);
    	}
    	FOR(i, 1, n) {
    		if(close[i]) continue;
    		bool bad = false;
    		for(int v : rg[i]) if(!close[v]) bad = true;
    		if(bad) {
    			for(int v : g[i]) {
    				if(!close[v]) {
    					++ans;
    					close[v] = 1;
    				}
    			}
    		}
    	}
    	cout << ans << endl;
    	FOR(i, 1, n) if(close[i]) cout << i << ' ';
    	cout << endl;
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

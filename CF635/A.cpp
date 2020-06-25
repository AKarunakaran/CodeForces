#include <bits/stdc++.h>
using namespace std;
#define int long long
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

int n, k, d[N], sz[N];
vector<int> g[N];
ll add[N];

void dfs(int s, int p = 0) {
	sz[s] = 1;
	ll removing = 0;
	for(int v : g[s]) {
		if(v != p) {
			d[v] = d[s]+1;
			dfs(v, s);
			sz[s] += sz[v];
			removing += d[v]*sz[v];
		}
	}
	// cout << s << ' ' << removing << endl;
	add[s] = d[s]*sz[s]-removing;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> k;
    REP(_, n-1) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    d[1] = 0;
    dfs(1);
    // FOR(i, 1, n) cout << d[i] << ' ';
    // cout << endl;
    // FOR(i, 1, n) cout << sz[i] << ' ';
    // cout << endl;
    // FOR(i, 1, n) cout << add[i] << ' ';
    // cout << endl;
    sort(add+1, add+1+n);
    reverse(add+1, add+1+n);
    ll ans = 0;
    FOR(i, 1, k) ans += add[i];
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

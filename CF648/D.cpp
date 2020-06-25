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

const int N = 50;

int t, n, m, vis[N][N], numhit, numg;
string g[N];

bool in_bounds(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

bool surround(int r, int c) {
	vector<pii> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	for(auto [dr, dc] : dir) {
		int nr = r+dr, nc = c+dc;
		if(!in_bounds(nr, nc)) continue;
		if(g[nr][nc] == 'G') return false;
		if(g[nr][nc] == '.') g[nr][nc] = '#';
	}
	return true;
}

bool path(int r, int c) {
	if(g[r][c] == 'B') return false;
	if(g[r][c] == 'G') ++numhit;
	vis[r][c] = 1;
	vector<pii> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	for(auto [dr, dc] : dir) {
		int nr = r+dr, nc = c+dc;
		if(in_bounds(nr, nc) && !vis[nr][nc] && g[nr][nc] != '#' && !path(nr, nc)) return false;
	}
	return true;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	memset(vis, 0, sizeof(vis));
    	cin >> n >> m;
    	REP(i, n) cin >> g[i];
    	bool good = true;
    	numg = 0;
    	REP(i, n) {
    		REP(j, m) {
    			if(g[i][j] == 'G') ++numg;
    			if(g[i][j] == 'B') {
    				if(!surround(i, j)) {
    					good = false;
    					break;
    				}
    			}
    		}
    		if(!good) break;
    	}
    	numhit = 0;
    	if(g[n-1][m-1] != '#') {
    		if(!path(n-1, m-1)) good = false;
    	}
    	if(numhit != numg) good = false;
    	cout << (good ? "Yes" : "No") << endl;
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

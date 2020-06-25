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

int n, m, q, d[N][N];
string g[N];

vector<pii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<pii> nxt;

bool in_bounds(int r, int c) {return r >= 0 && c >= 0 && r < n && c < m;}

bool good(int r, int c) {
	bool res = false;
	for(auto[dr, dc] : dir) {
		int nr = r+dr, nc = c+dc;
		if(in_bounds(nr, nc) && g[nr][nc] == g[r][c]) {
			res = true;
		}
	}
	return res;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(d, -1, sizeof(d));
    cin >> n >> m >> q;
    REP(i, n) cin >> g[i];

    REP(i, n) {
    	REP(j, m) {
    		if(good(i, j)) {
    			nxt.push({i, j});
    			d[i][j] = 0;
    		}
    	}
    }
    while(!nxt.empty()) {
    	int r, c;
    	tie(r, c) = nxt.front(); nxt.pop();
    	for(auto[dr, dc] : dir) {
    		int nr = r+dr, nc = c+dc;
    		if(in_bounds(nr, nc) && d[nr][nc] == -1) {
    			d[nr][nc] = d[r][c]+1;
    			nxt.push({nr, nc});
    		}
    	}
    }

    while(q--) {
    	int i, j;
    	ll p;
    	cin >> i >> j >> p;
    	--i, --j;
    	int cur = g[i][j]-'0';
    	if(d[i][j] != -1 && p > d[i][j]) cur ^= ((p-d[i][j]) & 1);
    	cout << cur << endl;
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

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

void bad() {
	cout << -1 << endl;
	exit(0);
}

const int N = 1e3+10;

string s[N];
int n, m, vis[N][N];

void check_row(int r) {
	bool start = false, stopped = false;
	REP(i, m) {
		if(s[r][i] == '#'){
			if(!start) {
				start = true;
			} else if(stopped) {
				bad();
			}
		} else {
			if(start) {
				stopped = true;
			}
		}
	}
}

void check_col(int c) {
	bool start = false, stopped = false;
	REP(i, n) {
		if(s[i][c] == '#'){
			if(!start) {
				start = true;
			} else if(stopped) {
				bad();
			}
		} else {
			if(start) {
				stopped = true;
			}
		}
	}
}

inline bool in_bounds(int r, int c) {return r >= 0 && c >= 0 && r < n && c < m;}

void dfs(int r, int c) {
	vis[r][c] = 1;
	vector<pii> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	for(auto [dr, dc] : dir) {
		int nr = r+dr, nc = c+dc;
		if(in_bounds(nr, nc) && s[nr][nc] == '#' && !vis[nr][nc]) dfs(nr, nc);
	}
}

bool row_empty(int r) {
	bool good = true;
	REP(j, m) if(s[r][j] == '#') good = false;
	return good;
}

bool col_empty(int c) {
	bool good = true;
	REP(i, n) if(s[i][c] == '#') good = false;
	return good;
}

void check_empties() {
	int rows = 0, cols = 0;
	REP(i, n) if(row_empty(i)) ++rows;
	REP(i, m) if(col_empty(i)) ++cols;
	if((rows && !cols) || (!rows && cols)) bad();
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m;
    REP(i, n) cin >> s[i];
    check_empties();
    REP(i, n) check_row(i);
    REP(j, m) check_col(j);

    int cc = 0;
    REP(i, n) {
    	REP(j, m) {
    		if(s[i][j] == '#' && !vis[i][j]) {
    			++cc;
    			dfs(i, j);
    		}
    	}
    }
    cout << cc << endl;

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

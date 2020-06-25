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

const int N = 510;

int n, m, q, sq[N][N];
string g[N];

void grow(int r, int c) {
	sq[r][c] = 1;
	int gsz = 1;
	while(1) {
		int r1 = r-gsz, r2 = r+1+gsz, c1 = c-gsz, c2 = g+1+gsz;
		if(!in_bounds(r1, c1) || !in_bounds(r2, c2)) return;
		FOR(i, r1, r) if(g[i][c1] != 'R') return;
		FOR(i, c1, c) if(g[r1][i] != 'R') return;
		FOR(i, r+1, r2) if(g[i][c1] != 'Y') return;
		FOR(i, c1, c) if(g[r2][i] != 'Y') return;
		FOR(i, r1, r) if(g[i][c2] != 'G') return;
		FOR(i, c+1, c2) if(g[r1][i] != 'G') return;
		FOR(i, r+1, r2) if(g[i][c2] != 'B') return;
		FOR(i, c+1, c2) if(g[r2][i] != 'B') return;
		sq[r1][r2] = 1+gsz;
		++gsz;
	}
}

int query(int r1, int c1, int r2, int c2) {
	//
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> m >> q;
    REP(i, n) cin >> g[i];
    REP(i, n-1) REP(j, m-1) if(g[i][j] == 'R' && g[i+1][j] == 'Y' && g[i][j+1] == 'G' && g[i+1][j+1] == 'B') grow(i, j);
    // 
    while(q--) {
    	int r[2], c[2];
    	REP(i, 2) cin >> r[i] >> c[i];
    	cout << query(r[0], c[0], r[1], c[1]) << endl;
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

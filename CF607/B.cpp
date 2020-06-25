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

const int N = 70;
int t, r, c;
string g[N];

bool allrow(int tr) {
	REP(i, c) if(g[tr][i] == 'P') return false;
	return true;
}

bool allcol(int tc) {
	REP(i, r) if(g[i][tc] == 'P') return false;
	return true;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> r >> c;
    	REP(i, r) cin >> g[i];
    	int cnt = 0;
    	REP(i, r) REP(j, c) cnt += g[i][j] == 'A';
    	if(cnt == 0) {
    		cout << "MORTAL" << endl;
    		continue;
    	} else if(cnt == r*c) {
    		cout << 0 << endl;
    		continue;
    	}
    	// If an edge is all 'A', then 1
    	if(allrow(0) || allrow(r-1) || allcol(0) || allcol(c-1)) {
    		cout << 1 << endl;
    		continue;
    	}

    	// If a corner is 'A', then 2
    	// If a row/column is all 'A', then 2
    	if(g[0][0] == 'A' || g[0][c-1] == 'A' || g[r-1][0] == 'A' || g[r-1][c-1] == 'A') {
    		cout << 2 << endl;
    		continue;
    	}

    	bool g1 = false, g2 = false;
    	REP(i, r) if(allrow(i)) g1 = true;
    	REP(i, c) if(allcol(i)) g2 = true;
    	if(g1 || g2) {
    		cout << 2 << endl;
    		continue;
    	}

    	// If any on border then 3
    	g1 = false, g2 = false;
    	REP(i, r) {
    		if(g[i][0] == 'A') g1 = true;
    		if(g[i][c-1] == 'A') g2 = true;
    	}
    	if(g1 || g2) {
    		cout << 3 << endl;
    		continue;
    	}
    	g1 = false, g2 = false;
    	REP(i, c) {
    		if(g[0][i] == 'A') g1 = true;
    		if(g[r-1][i] == 'A') g2 = true;
    	}
    	if(g1 || g2) {
    		cout << 3 << endl;
    		continue;
    	}

    	// else 4
    	cout << 4 << endl;
    }


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

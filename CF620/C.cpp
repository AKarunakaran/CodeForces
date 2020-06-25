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

const int N = 1e5+10;

int n, m, q;

bool in_bounds(int lo, int hi, int l, int h) {
	return l <= lo && lo <= hi && hi <= h;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> q;
    while(q--) {
    	cin >> n >> m;
    	int lo = m, hi = m, curt = 0, lb = -1e9, hb = 1e9;
    	bool good = true;
    	REP(i, n) {
    		int t, l, h;
    		cin >> t >> l >> h;
    		int dif = t-curt;
    		lb = l;
    		hb = h;
    		lo = max(lo-dif, lb);
    		hi = min(hi+dif, hb);
    		curt = t;
    		// cout << curt << "  " << lo << ' ' << hi << ' ' << lb << ' ' << hb << endl;
    		if(!in_bounds(lo, hi, lb, hb)) good = false;
    	}
    	cout << (good ? "YES" : "NO") << endl;
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

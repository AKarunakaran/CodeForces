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
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;

int t, a, b, c, d, x, y, x1, yy1, x2, y2;

bool inside(int tx, int ty) {
	return tx <= x2 && tx >= x1 && ty <= y2 && ty >= yy1;
}

bool need_up(bool can) {
	if(d == 0 && c == 0) return true;
	return can;
}

bool need_right(bool can) {
	if(a == 0 && b == 0) return true;
	return can;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	cin >> a >> b >> c >> d >> x >> y >> x1 >> yy1 >> x2 >> y2;
    	int dx = b-a, dy = d-c;
    	int fx = x+dx, fy = y+dy;
    	bool can_move_up = yy1 != y2, can_move_right = x1 != x2;

    	cout << (inside(fx, fy) && inside(x, y) && need_up(can_move_up) && need_right(can_move_right) ? "YES" : "NO") << endl;
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

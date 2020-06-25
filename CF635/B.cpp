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
// const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 1e5+10;

int t, n[3], a[3][N], id[3], ans;

bool valid_move(int i) {
	return id[i]+1 < n[i];
}

inline int elt(int i) {return a[i][id[i]];}

// true iff i better to move than j
bool better_than(int i, int j) {
	return elt(i) <= elt(j) || !valid_move(j);
}

inline int sq(int x) {return x*x;}

int get_ans(int x, int y, int z) {
	return sq(x-y)+sq(y-z)+sq(z-x);
}

void solve() {
	memset(id, 0, sizeof(id));
	ans = min(ans, get_ans(elt(0), elt(1), elt(2)));
	while(1) {
		REP(i, 3) {
			if(valid_move(i)){
				++id[i];
				ans = min(ans, get_ans(elt(0), elt(1), elt(2)));
				--id[i];
			}
		}
		int move = -1;
		REP(i, 3) {
			if(!valid_move(i)) continue;
			int oth1 = (i+1)%3, oth2 = (i+2)%3;
			if(better_than(i, oth1) && better_than(i, oth2)) {
				move = i;
			}
		}
		if(move == -1) break;
		++id[move];
		ans = min(ans, get_ans(elt(0), elt(1), elt(2)));
	}
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> t;
    while(t--) {
    	REP(i, 3) cin >> n[i];
    	REP(i, 3) REP(j, n[i]) cin >> a[i][j];
    	REP(i, 3) sort(a[i], a[i]+n[i]);
    	ans = INF;
    	solve();
    	REP(i, 3) reverse(a[i], a[i]+n[i]);
    	REP(i, 3) REP(j, n[i]) a[i][j] *= -1;
    	solve();
    	cout << ans << endl;
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

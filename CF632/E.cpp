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

const int N = 510;

void bad() {
	cout << -1 << endl;
	exit(0);
}

int n, ans[N][N], cur = 1;

void fill_square(int r, int c) {
	if(ans[r][c] == 0)
		ans[r][c] = cur++;
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n;
    if(n <= 2) bad();
    if(n == 3) {
    	cout << "1 2 4" << endl;
    	cout << "5 3 8" << endl;
    	cout << "9 7 6" << endl;
    	exit(0);
    } else if(n == 4) {
    	cout << "4 3 6 12" << endl;
    	cout << "7 5 9 15" << endl;
    	cout << "14 1 11 10" << endl;
		cout << "13 8 16 2" << endl;
		exit(0);
    } else if(n == 5) {
    	ans[0][1] = n*n;
    	ans[n-1][0] = n*n-3;
    	ans[n-1][1] = n*n-2;
    	ans[n-1][2] = n*n-1;
    } else {
    	ans[0][2] = n*n;
    	ans[n-2][1] = n*n-3;
    	ans[n-2][2] = n*n-2;
    	ans[n-2][3] = n*n-1;
    }
    REP(i, n) {
    	if(i & 1) FOR(j, 0, n-2) fill_square(i, j);
    	else FORD(j, n-2, 0) fill_square(i, j);
    }
    FORD(i, n-1, 0) fill_square(i, n-1);
    REP(i, n) {
    	REP(j, n) cout << ans[i][j] << ' ';
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

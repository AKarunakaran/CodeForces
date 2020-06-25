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
int r, c;
ll g[N][N];

int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> r >> c;
    if(r == 1 && c == 1) {
    	cout << 0 << endl;
    	exit(0);
    }
    bool swapped = false;
    if(r > c) {
    	swapped = true;
    	swap(r, c);
    }
    FOR(i, 1, r) FOR(j, 1, c) g[i][j] = 1;
    FOR(i, 1, r) FOR(j, 1, c) g[i][j] *= i/gcd(i, g[i][j]);
    FOR(j, 1, c) FOR(i, 1, r) g[i][j] *= (r+j)/gcd((r+j), g[i][j]);
    // Debugging
    // FOR(i, 1, r) {
    // 	int gc = 0;
    // 	FOR(j, 1, c) gc = gcd(gc, g[i][j]);
    // 	assert(gc == i);
    // }
    // FOR(j, 1, c) {
    // 	int gc = 0;
    // 	FOR(i, 1, r) gc = gcd(gc, g[i][j]);
    // 	assert(gc == r+j);
    // }
    if(swapped) {
    	FOR(i, 1, c) {
    		FOR(j, 1, r) cout << g[j][i] << ' ';
    		cout << endl;
    	}
    } else {
	    FOR(i, 1, r) {
	    	FOR(j, 1, c) cout << g[i][j] << ' ';
	    	cout << endl;
	    }
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
